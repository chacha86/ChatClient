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
		int recvFlag; // ������ �޽����� �Դ����� üũ�ϴ� �÷��װ�
		char msgBuffer[100]; // ���� �޽��� ���� ����
		int msgBufferIndex; // ������ ���� �ε���

		void repaintWhenRecvFromServer();
		void sendToServer();

	public:
		ChatController();
		void setRecvFlag(int recvFlag);
		void run();

	};
}

#endif