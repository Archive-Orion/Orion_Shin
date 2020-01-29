#include <iostream>
#include <WinSock2.h>		//소켓을 사용하기위한 헤더파일

#pragma comment(lib, "ws2_32")	//위에서 선언한 헤더파일들을 가져다 쓰기위한 링크

#define PORT		0330
#define PACKET_SIZE	1024

int main(void) {
	WSADATA wsaData;		//Windows의 소켓 초기화 정보를 저장하기위한 구조체
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET hListen;
	hListen = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	WSACleanup();
}