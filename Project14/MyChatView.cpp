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

void ChatView::gotoxy(int x, int y) {
	//x, y 좌표 설정
	COORD pos = { x,y };
	//커서 이동
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
		if (flag == 1) { // 서버에서 메시지가 왔을 때,
			// 채팅 메시지 저장
			msgList.push_back("서버에서 메시지가 옴..");

			// 채팅창 다시 그리기
			system("cls");
			printChatWindow();
			setChatDataList();

			// 입력중이던 채팅 메시지를 다시 그려줌
			for (int i = 0; i < index; i++) {
				cout << msgBuffer[i];
			}

			// 입력 커서를 index 위치로 바꿈
			gotoxy(index, y);

			// 평상시 상태로 바꿈
			flag = 0;
		}
		if (kbhit()) { // 키보드가 입력됐을 때
			char c = getch(); // 키값을 가져오고

			if (c == 13) { // 엔터라면

				// 내 메시지를 msgList에 넣는다.
				msgList.push_back(msgBuffer);
				// 메시지를 보냈으므로 채팅창 다시 그리고
				memset(msgBuffer, 0, sizeof(msgBuffer)); // msgBuffer의 내용 비운다.

				system("cls");
				printChatWindow();
				setChatDataList();

				// 메시지를 보냈으므로 메시지 버퍼 index초기화, 커서의 x값 초기화
				index = 0;
				x = 0;

				// 입력 커서를 가장 앞으로 돌린다.
				gotoxy(x, y);


			}
			else if (c == 8)
			{
				// todo. 백스페이스 입력시 입력버퍼 한개씩 줄이기 구현			
			}
			else {
				msgBuffer[index++] = c;
			}

			cout << c;
		}
	}
}
