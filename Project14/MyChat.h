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
		char msgBuffer[100]; // ���� �޽��� ���� ����
		int index; // ������ ���� �ε���
		int x; // ä�� �޽����� �Է��ϴ� ���� x��ǥ.
		int y; // ä�� �޽����� �Է��ϴ� ���� y��ǥ.
		int flag; // ������ �޽����� �Դ����� üũ�ϴ� �÷��װ�
		int setDataX; // �޽����� â�� �°� �׸������� x��ǥ��
		int setDataY; // �޽����� â�� �°� �׸������� y��ǥ��

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