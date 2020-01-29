#include <iostream>
#include <stdlib.h>
#include <WinSock2.h>		//������ ����ϱ����� �������

#pragma comment(lib, "ws2_32")	//������ ������ ������ϵ��� ������ �������� ��ũ

#define PORT		0330
#define PACKET_SIZE	1024
#define _WINSOCK_DEPRECATED_NO_WARNINGS

using namespace std;

int main(void) {
	WSADATA wsaData;		//Windows�� ���� �ʱ�ȭ ������ �����ϱ����� ����ü
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET server;
	server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN server_addr = {};
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(server, (SOCKADDR*)&server_addr, sizeof(server_addr));
	listen(server, SOMAXCONN);

	SOCKADDR_IN client_addr = {};
	int clientsize = sizeof(client_addr);
	SOCKET client = accept(server, (SOCKADDR*)&client_addr, &clientsize);

	char client_buffer[PACKET_SIZE] = {};
	recv(client, client_buffer, PACKET_SIZE, 0);
	cout << client_buffer << endl;

	char msg[] = "Server send";
	send(client, msg, strlen(msg), 0);

	closesocket(client);
	closesocket(server);

	WSACleanup();
	return 0;
}