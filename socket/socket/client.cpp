//#include <iostream>
//#include <WinSock2.h>
//
//#pragma comment(lib, "ws2_32")
//
//#define	PORT		0330
//#define PACKET_SIZE	1024
//#define SERVER_IP	"192.168.107.1"
//
//using namespace std;
//
//int main(void) {
//	WSADATA wsaData;
//	WSAStartup(MAKEWORD(2, 2), &wsaData);
//	
//	SOCKET sock;
//	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//
//	SOCKADDR_IN	addr = {};
//	addr.sin_family = AF_INET;
//	addr.sin_port = htons(PORT);
//	addr.sin_addr.s_addr = inet_addr(SERVER_IP);
//
//	connect(sock, (SOCKADDR*)&addr, sizeof(addr));
//
//	char msg[] = "Client send";
//	send(sock, msg, strlen(msg), 0);
//
//	char client_buffer[PACKET_SIZE] = {};
//	recv(sock, client_buffer, PACKET_SIZE, 0);
//	cout << client_buffer << endl;
//
//	closesocket(sock);
//
//	WSACleanup();
//	return 0;
//}