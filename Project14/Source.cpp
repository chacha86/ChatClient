#include "MySocket.h"
#include <string.h>
#pragma comment(lib, "ws2_32") // 윈도우 소켓 프로그래밍 기능 제공 라이브러리
#define SIZE 5
#define ID_SIZE 10
using namespace std;
using namespace MySocket;
Socket* skt = NULL;
SocketData sktData_list[SIZE];

char* concat(const char* s1, const char* s2) {
	char* res = new char[strlen(s1) + strlen(s2) + 1];
	strcpy(res, s1);
	strcat(res, s2);
	return res;
}

void recv_back() {
	while (true) {
		skt->print_data();
	}
}

void send_msg() {
	while (true) {
		const char* str1 = "user1 : ";
		char msg[100] = { 0 };
		cout << str1;
		cin.getline(msg, sizeof(msg));
		char* rst = concat(str1, msg);
		skt->send_data(rst);
	}
}

int main() {

	skt = new Socket(9999, "127.0.0.1");

	thread t1(recv_back);
	send_msg();

	t1.join();

	return 0;
}