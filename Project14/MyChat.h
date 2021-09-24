#ifndef MY_CHAT
#define MY_CHAT
#include <vector>
#include <string>
namespace MyChat {
	
	/*typedef struct ChatData {
		string userId;
		string msg;
	} ChatData;*/

	class ChatView {
	private:
		std::vector<std::string> msgList;
		//vector<ChatData*> chatDataList;
		char msgBuffer[100]; // 보낼 메시지 저장 버퍼
		int index; // 버퍼의 현재 인덱스
		int x; // 채팅 메시지를 입력하는 곳의 x좌표.
		int y; // 채팅 메시지를 입력하는 곳의 y좌표.
		int flag; // 서버에 메시지가 왔는지를 체크하는 플래그값
		int setDataX; // 메시지를 창에 맞게 그리기위한 x좌표값
		int setDataY; // 메시지를 창에 맞게 그리기위한 y좌표값

	public:
		ChatView();
		void gotoxy(int x, int y);
		void printSendMsg();
		void setChatDataList();
		void printChatWindow();
		void setFlag(int flag);
	};

}

#endif