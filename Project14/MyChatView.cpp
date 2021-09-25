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
	cout << "##                    채팅 프로그램 v1                     ##" << endl;
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
	// 채팅 메시지 저장
	msgList.push_back("서버에서 메시지가 옴..");

	// 채팅창 다시 그리기
	paintChatDisplay();

	// 입력중이던 채팅 메시지를 다시 그려줌
	for (int i = 0; i < msgBufferIndex; i++) {
		cout << msgBuffer[i];
	}

	// 입력 커서를 index 위치로 바꿈
	chatInputPos.X = msgBufferIndex;
	gotoxy(chatInputPos);

	// 평상시 상태로 바꿈
	recvFlag = 0;
}

void ChatView::sendToServer() {
	// 내 메시지를 msgList에 넣는다.
	msgList.push_back(msgBuffer);
	// 메시지를 보냈으므로 채팅창 다시 그리고
	memset(msgBuffer, 0, sizeof(msgBuffer)); // msgBuffer의 내용 비운다.

	paintChatDisplay();

	// 메시지를 보냈으므로 메시지 버퍼 index초기화, 커서의 x값 초기화
	msgBufferIndex = 0;
	chatInputPos.X = 0;

	// 입력 커서를 가장 앞으로 돌린다.
	gotoxy(chatInputPos);
}

void ChatView::run() {
	while (true) {
		if (recvFlag == 1) { // 서버에서 메시지가 왔을 때,
			repaintWhenRecvFromServer();
		}
		if (kbhit()) { // 키보드가 입력됐을 때
			char key = getch(); // 키값을 가져오고

			if (key == ENTER) { // 엔터라면
				sendToServer();
			} else if (key == BACKSPACE) {

			} else {
				msgBuffer[msgBufferIndex++] = key;
				cout << key;
			}
		}
	}
}
