#include <iostream>
#include <WinSock2.h>		//������ ����ϱ����� �������

#pragma comment(lib, "ws2_32")	//������ ������ ������ϵ��� ������ �������� ��ũ

#define PORT		0330
#define PACKET_SIZE	1024

int main(void) {
	WSADATA wsaData;		//Windows�� ���� �ʱ�ȭ ������ �����ϱ����� ����ü
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET hListen;
	hListen = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	WSACleanup();
}