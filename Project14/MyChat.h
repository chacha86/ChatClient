#ifndef MY_CHAT
#define MY_CHAT
#include <vector>
#include <string>
#include <windows.h>
namespace MyChat {
	class ChatView {
	private:
		std::vector<std::string> msgList;
		//vector<ChatData*> chatDataList;
		COORD chatInputPos;
		COORD msgPrintPos;
		char msgBuffer[100]; // ���� �޽��� ���� ����
		int msgBufferIndex; // ������ ���� �ε���
		int recvFlag; // ������ �޽����� �Դ����� üũ�ϴ� �÷��װ�
		void repaintWhenRecvFromServer();
		void sendToServer();
		void gotoxy(COORD pos);
		void setChatDataList();
		void printChatWindow();

	public:
		ChatView();
		void paintChatDisplay();
		void run();
		void setRecvFlag(int recvFlag);
	};

}

#endif