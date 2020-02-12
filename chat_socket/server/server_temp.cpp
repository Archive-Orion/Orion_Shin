#include <iostream>
#include <process.h> 
#include <WinSock2.h>
#include <windows.h> 

#pragma comment(lib, "ws2_32") 
#define PORT 5000
#define MAX_CLIENT 4 
#define MAX_SOCKET 65535 

using namespace std;

void recv_client(void* ns);
int client_count = 0;
int client_num = 0;
SOCKET client[MAX_SOCKET];
HANDLE Mutex = 0;

int main() {
	printf("+----------------------------+\n");
	printf("|           SERVER           |\n");
	printf("+----------------------------+\n");



	Mutex = CreateMutex(NULL, FALSE, NULL);
	if (!Mutex) {
		cout << "Mutex error" << endl;
		CloseHandle(Mutex);
		return 1;
	}



	WSADATA data;
	if (WSAStartup(MAKEWORD(2, 2), &data) != 0) {
		cout << "WSAStartup error" << endl;
		WSACleanup();
		return 1;
	}



	SOCKET server;
	int addrsize, ret;
	SOCKADDR_IN server_addr, client_addr;

	server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (server == SOCKET_ERROR) {
		cout << "socket error" << endl;
		closesocket(server);
		WSACleanup();
		return 1;
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);



	if (bind(server, (SOCKADDR*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
		cout << "bind error" << endl;
		closesocket(server);
		WSACleanup();
		return 1;
	}

	printf("Ŭ���̾�Ʈ�� ��ٸ��ϴ�. %d ����\n", MAX_CLIENT - client_count);
	listen(server, SOMAXCONN);
	addrsize = sizeof(client_addr);



	while (1) {
		client[client_num] = accept(server, (sockaddr*)&client_addr, &addrsize);

		if (client_count < MAX_CLIENT) {
			if (client[client_num] != INVALID_SOCKET || client[client_num] != SOCKET_ERROR) {}
			_beginthread(recv_client, 0, &client[client_num]);
			cout << client_num << "�� Ŭ���̾�Ʈ " << inet_ntoa(client_addr.sin_addr) << ":" << ntohs(client_addr.sin_port) << " ���� ����" << endl;
		}
		else {
			addrsize = sizeof(client_addr);
			if (client[client_num] == INVALID_SOCKET) {
				cout << "accept error" << endl;
				closesocket(client[client_num]);
				closesocket(server);
				WSACleanup();
				return 1;
			}

			char full[] = "full";
			ret = send(client[client_num], full, sizeof(full), 0);
			closesocket(client[client_num]);
		}
	}

	return 0;
}

void recv_client(void* ns) {
	WaitForSingleObject(Mutex, INFINITE);
	client_count++;
	client_num++;
	cout << "���� " << MAX_CLIENT - client_count << "�� ����" << endl;

	ReleaseMutex(Mutex);

	char welcome[50] = { 0 };
	char buff[1024] = { 0 };
	int ret, i;

	itoa(client_num, welcome, 10);
	strcat(welcome, "�� Ŭ���̾�Ʈ, ȯ���մϴ�.\n\0");
	ret = send(*(SOCKET*)ns, welcome, sizeof(welcome), 0);

	while (ret != SOCKET_ERROR || ret != INVALID_SOCKET) {
		ret = recv(*(SOCKET*)ns, buff, 1024, 0);



		for (i = 0; i < MAX_SOCKET; i++) {
			WaitForSingleObject(Mutex, INFINITE);
			if (((unsigned*)&client[i] != (SOCKET*)ns)) {
				send(client[i], buff, strlen(buff), 0);
			}

			ReleaseMutex(Mutex);
		}

		if (strlen(buff) != 0)
			printf("%d�� Ŭ���̾�Ʈ �޽��� ���� : %s", client_num, buff);

		memset(buff, 0, 1024);
	}



	WaitForSingleObject(Mutex, INFINITE);
	client_count--;
	printf("%d Ŭ���̾�Ʈ ����\n���� %d�� ����\n", client_num, MAX_CLIENT - client_count);
	ReleaseMutex(Mutex);

	closesocket(*(int*)ns);
	return;
}