#include "MySocket.h"
#include "MyChat.h"
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <sstream>
#include <map>
#pragma comment(lib, "ws2_32") // ������ ���� ���α׷��� ��� ���� ���̺귯��
#define SIZE 5
#define ID_SIZE 10
using namespace std;
using namespace MySocket;
//using namespace MyChat;

string loginedUser;
Socket* skt = NULL;
string tmpSendMsg;
int tmpSaveFlag = false;
int isFirstMsg = true;
char sendBuff[100];
char sendBuffSize = 0;
//vector<ChatData*> chatDataList = vector<ChatData*>();

//void printChatMsg() {
//	//system("cls");
//	cout << "================ ä�� v1 ================" << endl;
//	for (ChatData* chatData : chatDataList) {
//		cout << chatData->userId << " : ";
//		cout << chatData->msg << endl;
//	}
//	cout << "=========================================" << endl;
//	//printSendMsg();
//	tmpSaveFlag = false;
//}
//
//vector<string> split(string input, char delimiter) {
//	vector<string> answer;
//	stringstream ss(input);
//	string temp;
//
//	while (getline(ss, temp, delimiter)) {
//		answer.push_back(temp);
//	}
//
//	return answer;
//}
//
//ChatData* mapToChatData(map<string, string> chatMap) {
//	ChatData* chatData = new ChatData();
//	chatData->userId = chatMap["userId"];
//	chatData->msg = chatMap["msg"];
//
//	return chatData;
//}
//
//const char* toChatDataBytes(ChatData* chatData) {
//	string data = "";
//	data = data.append("userId:");
//	data = data.append(chatData->userId);
//	data = data.append("msg:");
//	data = data.append(chatData->msg);
//
//	return data.c_str();
//}
//
//ChatData* toChatDataObject(string msg) {
//
//	vector<string> msgBits= split(msg, ',');
//	map<string, string> chatMap;
//	for (string msgBit : msgBits) {
//		vector<string> keyAndValue = split(msgBit, ':');
//		chatMap[keyAndValue[0]] = keyAndValue[1];
//	}
//	ChatData* chatData = mapToChatData(chatMap);
//	cout << "chatData -> userId : " << chatData->userId << endl;
//	cout << "chatData -> msg : " << chatData->msg << endl;
//	return chatData;
//}
//
//void recvBack() {
//	char recvMsg[100] = {0};
//	while (true) {
//		strcpy(recvMsg, skt->recv_data());
//		cout << "recvMsg : " << recvMsg << endl;
//		if (!isFirstMsg) {
//			ChatData* chatData = toChatDataObject(string(recvMsg));
//			chatDataList.push_back(chatData);
//		}
//		tmpSaveFlag = true;
//		printChatMsg();
//	}
//}
//=====>  Todo. ���ο� �޽����� ���� ä�� â�� �ٽ� �׷����� �Է��ߴ� ���� �����ϱ� ���� ���
// 1. �޽��� ���ۿ� getch�� �Է°� �ױ�
// 2. �������� �޽��� ���� �ٽ� �׷����Ƿ� ������ ��ġ ����ߴٰ� �޽��� ���� ��� �� �ڿ� �ٽ� �ۼ�
// 3. ���� �ļ� �޽��� �����ϸ� �޽��� ���� ����
MyChat::ChatView* cv = new MyChat::ChatView();
void test() {
	while (true) {
		this_thread::sleep_for(chrono::milliseconds(5000));
		cv->setRecvFlag(1);
	}
}

//=======================================================
int main() {

	cout << "����� �̸��� �Է����ּ��� : ";
	cin >> loginedUser;
	cv->paintChatDisplay();
	thread t1(test);
	cv->run();
	t1.join();

	//skt = new Socket(9999, "127.0.0.1");

	//thread t1(recvBack);
	//t1.join();

	return 0;
}
