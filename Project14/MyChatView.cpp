#include "MyChat.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace MyChat;
using namespace std;

ChatView::ChatView() {
	//this->chatDataList = vector<ChatData*>();
	memset(this->msgBuffer, 0, sizeof(msgBuffer));
	this->index = 0; 
	this->x = 0;
	this->y = 16;
	this->flag = 0;
	setDataX = 2;
	setDataY = 3;
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

void ChatView::gotoxy(int x, int y) {
	//x, y ��ǥ ����
	COORD pos = { x,y };
	//Ŀ�� �̵�
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void ChatView::setChatDataList() {
	int ty = 0;
	for (string msg : msgList) {
		gotoxy(setDataX, setDataY + ty);
		cout << msg;
		ty++;
	}
	gotoxy(x, y);
}

void ChatView::setFlag(int flag) {
	this->flag = flag;
}

void ChatView::printSendMsg() {
	while (true) {
		if (flag == 1) { // �������� �޽����� ���� ��,
			// ä�� �޽��� ����
			msgList.push_back("�������� �޽����� ��..");

			// ä��â �ٽ� �׸���
			system("cls");
			printChatWindow();
			setChatDataList();

			// �Է����̴� ä�� �޽����� �ٽ� �׷���
			for (int i = 0; i < index; i++) {
				cout << msgBuffer[i];
			}

			// �Է� Ŀ���� index ��ġ�� �ٲ�
			gotoxy(index, y);

			// ���� ���·� �ٲ�
			flag = 0;
		}
		if (kbhit()) { // Ű���尡 �Էµ��� ��
			char c = getch(); // Ű���� ��������

			if (c == 13) { // ���Ͷ��

				// �� �޽����� msgList�� �ִ´�.
				msgList.push_back(msgBuffer);
				// �޽����� �������Ƿ� ä��â �ٽ� �׸���
				memset(msgBuffer, 0, sizeof(msgBuffer)); // msgBuffer�� ���� ����.

				system("cls");
				printChatWindow();
				setChatDataList();

				// �޽����� �������Ƿ� �޽��� ���� index�ʱ�ȭ, Ŀ���� x�� �ʱ�ȭ
				index = 0;
				x = 0;

				// �Է� Ŀ���� ���� ������ ������.
				gotoxy(x, y);


			}
			else if (c == 8)
			{
				// todo. �齺���̽� �Է½� �Է¹��� �Ѱ��� ���̱� ����			
			}
			else {
				msgBuffer[index++] = c;
			}

			cout << c;
		}
	}
}
