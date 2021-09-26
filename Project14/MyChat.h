#ifndef MY_CHAT
#define MY_CHAT
#include <vector>
#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>
namespace MyChat {
	class ChatView {
	private:
		//vector<ChatData*> chatDataList;
		COORD chatInputPos;
		COORD msgPrintPos;
		
		void setChatDataList(std::vector<std::string> msgList);
		void printChatWindow();
		void gotoxy(COORD pos);

	public:
		ChatView();
		void paintChatDisplay(std::vector<std::string> msgList);
		void instantiateChatInputPos();
		void instantiateMsgPrintPos();
		void moveToChatInputPosX(int x);

	};

	class ChatController {
	private:
		ChatView chatView;
		std::vector<std::string> msgList;
		int recvFlag; // 서버에 메시지가 왔는지를 체크하는 플래그값
		char msgBuffer[100]; // 보낼 메시지 저장 버퍼
		int msgBufferIndex; // 버퍼의 현재 인덱스

		void repaintWhenRecvFromServer();
		void sendToServer();

	public:
		ChatController();
		void setRecvFlag(int recvFlag);
		void run();

	};
}

#endif