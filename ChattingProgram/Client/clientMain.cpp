#include <iostream>
#include <WinSock2.h>
#include <string.h> 
#include <process.h> 
#pragma comment(lib,"ws2_32") 

#define PORT 5000 
#define IP "127.0.0.1"  

using namespace std;

void recv_thread(void*);
SOCKET sock;
int ret = 0;
HANDLE Mutex;

int main() {
	printf("+----------------------------+\n");
	printf("|           CLIENT           |\n");
	printf("+----------------------------+\n");



	Mutex = CreateMutex(NULL, FALSE, FALSE);
	if (!Mutex) {
		cout << "Mutex error" << endl;
		return 1;
	}



	WSADATA data;
	char buff[1024];
	if (WSAStartup(MAKEWORD(2, 2), &data) != 0) {
		cout << "WSAStartup error" << endl;
		return 1;
	}



	SOCKADDR_IN addr;

	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == SOCKET_ERROR) {
		cout << "socket error" << endl;
		closesocket(sock);
		WSACleanup();
		return 1;
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = inet_addr(IP);



	if (connect(sock, (SOCKADDR*)&addr, sizeof(addr)) == SOCKET_ERROR) {
		cout << "connect error" << endl;
		closesocket(sock);
		WSACleanup();
		return 1;
	}

	ret = recv(sock, buff, 1024, 0);

	if (!strcmp("full", buff)) {
		cout << "가득찼습니다." << endl;
		Sleep(1000);
		closesocket(sock);
		WSACleanup();
		return 0;
	}

	cout << "서버와 연결이 되었음" << endl;
	cout << buff << endl;



	_beginthread(recv_thread, 0, NULL);

	while (ret != INVALID_SOCKET || ret != SOCKET_ERROR) {
		cout << "보낼 메시지 입력: ";
		fgets(buff, 1024, stdin);

		if (ret == INVALID_SOCKET || ret == SOCKET_ERROR) break;

		ret = send(sock, buff, strlen(buff), 0);

		memset(buff, 0, 1024);
	}

	closesocket(sock);
	WSACleanup();

	return 0;
}



void recv_thread(void* pData) {
	int ret_thread = 65535;
	char buff_thread[1024] = { 0 };

	while (ret_thread != INVALID_SOCKET || ret_thread != SOCKET_ERROR) {
		ret_thread = recv(sock, buff_thread, sizeof(buff_thread), 0);

		if (ret_thread == INVALID_SOCKET || ret_thread == SOCKET_ERROR)
			break;

		cout << endl << "??" << "님의 메시지 받음: " << buff_thread;
		memset(buff_thread, 0, 1024);
	}

	WaitForSingleObject(Mutex, 100L);
	ret = INVALID_SOCKET;
	ReleaseMutex(Mutex);

	return;
}