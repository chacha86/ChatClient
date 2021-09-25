#include "MyChat.h"
#include <iostream>
#include <conio.h>
#define MSG_PRINT_POS_X 2
#define MSG_PRINT_POS_Y 3
#define CHAT_INPUT_POS_X 0
#define CHAT_INPUT_POS_Y 16
#define ENTER 13
#define BACKSPACE 8
using namespace MyChat;
using namespace std;

ChatView::ChatView() {
	//this->chatDataList = vector<ChatData*>();
	memset(this->msgBuffer, 0, sizeof(msgBuffer));
	this->msgBufferIndex = 0; 
	this->recvFlag = 0;
	chatInputPos.X = CHAT_INPUT_POS_X;
	chatInputPos.Y = CHAT_INPUT_POS_Y;
	msgPrintPos.X = MSG_PRINT_POS_X;
	msgPrintPos.Y = MSG_PRINT_POS_Y;
}

void ChatView::printChatWindow() {
	cout << "#############################################################" << endl;
	cout << "##                    ä�� ���α׷� v1                     ##" << endl;
	cout << "#############################################################" << endl;
	cout << "##                                                         ##" << endl;
	cout << "##                                                         ##" << endl;
	cout << "##                                                         ##" << endl;
	cout << "##                                                         ##" << endl;
	cout << "##                                                         ##" << endl;
	cout << "##                                                         ##" << endl;
	cout << "##                                                         ##" << endl;
	cout << "##                                                         ##" << endl;
	cout << "##                                                         ##" << endl;
	cout << "##                                                         ##" << endl;
	cout << "#############################################################" << endl;
	cout << "##                                                         ##" << endl;
	cout << "#############################################################" << endl;
}

void ChatView::gotoxy(COORD pos) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void ChatView::setChatDataList() {
	int rowCount = 0;
	for (string msg : msgList) {
		msgPrintPos.Y += rowCount;
		gotoxy(msgPrintPos);
		cout << msg;
		rowCount++;
		msgPrintPos.Y = MSG_PRINT_POS_Y;
	}
	gotoxy(chatInputPos);
}

void ChatView::setRecvFlag(int recvFlag) {
	this->recvFlag = recvFlag;
}

void ChatView::paintChatDisplay() {
	system("cls");
	printChatWindow();
	setChatDataList();
}

void ChatView::repaintWhenRecvFromServer() {
	// ä�� �޽��� ����
	msgList.push_back("�������� �޽����� ��..");

	// ä��â �ٽ� �׸���
	paintChatDisplay();

	// �Է����̴� ä�� �޽����� �ٽ� �׷���
	for (int i = 0; i < msgBufferIndex; i++) {
		cout << msgBuffer[i];
	}

	// �Է� Ŀ���� index ��ġ�� �ٲ�
	chatInputPos.X = msgBufferIndex;
	gotoxy(chatInputPos);

	// ���� ���·� �ٲ�
	recvFlag = 0;
}

void ChatView::sendToServer() {
	// �� �޽����� msgList�� �ִ´�.
	msgList.push_back(msgBuffer);
	// �޽����� �������Ƿ� ä��â �ٽ� �׸���
	memset(msgBuffer, 0, sizeof(msgBuffer)); // msgBuffer�� ���� ����.

	paintChatDisplay();

	// �޽����� �������Ƿ� �޽��� ���� index�ʱ�ȭ, Ŀ���� x�� �ʱ�ȭ
	msgBufferIndex = 0;
	chatInputPos.X = 0;

	// �Է� Ŀ���� ���� ������ ������.
	gotoxy(chatInputPos);
}

void ChatView::run() {
	while (true) {
		if (recvFlag == 1) { // �������� �޽����� ���� ��,
			repaintWhenRecvFromServer();
		}
		if (kbhit()) { // Ű���尡 �Էµ��� ��
			char key = getch(); // Ű���� ��������

			if (key == ENTER) { // ���Ͷ��
				sendToServer();
			} else if (key == BACKSPACE) {

			} else {
				msgBuffer[msgBufferIndex++] = key;
				cout << key;
			}
		}
	}
}
