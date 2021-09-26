#include "MyChat.h"
#define ENTER 13
#define BACKSPACE 8

using namespace MyChat;
using namespace std;

ChatController::ChatController() {
	memset(this->msgBuffer, 0, sizeof(msgBuffer));
	this->msgBufferIndex = 0;
	this->recvFlag = 0;
	chatView.paintChatDisplay(msgList);
}

void ChatController::run() {
	while (true) {
		if (recvFlag == 1) { // �������� �޽����� ���� ��,
			repaintWhenRecvFromServer();
		}
		if (kbhit()) { // Ű���尡 �Էµ��� ��
			char key = getch(); // Ű���� ��������

			if (key == ENTER) { // ���Ͷ��
				sendToServer();
			}
			else if (key == BACKSPACE) {

			}
			else {
				msgBuffer[msgBufferIndex++] = key;
				cout << key;
			}
		}
	}
}

void ChatController::repaintWhenRecvFromServer() {
	// ä�� �޽��� ����
	msgList.push_back("�������� �޽����� ��..");

	// ä��â �ٽ� �׸���
	chatView.paintChatDisplay(msgList);

	// �Է����̴� ä�� �޽����� �ٽ� �׷���
	for (int i = 0; i < msgBufferIndex; i++) {
		cout << msgBuffer[i];
	}

	// �Է� Ŀ���� index ��ġ�� �ٲ�
	chatView.moveToChatInputPosX(msgBufferIndex);

	// ���� ���·� �ٲ�
	recvFlag = 0;
}

void ChatController::sendToServer() {
	// �� �޽����� msgList�� �ִ´�.
	msgList.push_back(msgBuffer);
	// �޽����� �������Ƿ� ä��â �ٽ� �׸���
	memset(msgBuffer, 0, sizeof(msgBuffer)); // msgBuffer�� ���� ����.

	chatView.paintChatDisplay(msgList);

	// �޽����� �������Ƿ� �޽��� ���� index�ʱ�ȭ, Ŀ���� ��ġ �ʱ�ȭ
	msgBufferIndex = 0;
	chatView.instantiateChatInputPos();

}

void ChatController::setRecvFlag(int recvFlag) {
	this->recvFlag = recvFlag;
}
