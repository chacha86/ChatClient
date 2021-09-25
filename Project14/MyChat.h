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
		char msgBuffer[100]; // 보낼 메시지 저장 버퍼
		int msgBufferIndex; // 버퍼의 현재 인덱스
		int recvFlag; // 서버에 메시지가 왔는지를 체크하는 플래그값
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