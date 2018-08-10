#include"stdafx.h"
#include <iostream>
#include <winsock2.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define SERVER_ADDR "127.0.0.1"
#define PORT 5500
#define BUFF_SIZE 2048

int _tmain(int argc, _TCHAR* argv[]){
	WSADATA wsaData;
	WORD wVersion = MAKEWORD(2, 2);
	if (WSAStartup(wVersion, &wsaData))
		printf("Version is not supported\n");
	SOCKET Client;
	Client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
	if (connect(Client, (sockaddr *)&serverAddr, sizeof(serverAddr))){
		printf("Error! Cannot connect server. %d", WSAGetLastError());
		getch();
		return 0;
	}
	printf("connected sever!\n");
	char buff[BUFF_SIZE];
	int ret;
	printf("Send to server: ");
	gets_s(buff, BUFF_SIZE);
	ret = recv(Client, buff, BUFF_SIZE, 0);
	if (ret == SOCKET_ERROR){
		if (WSAGetLastError() == WSAETIMEDOUT)
			printf("Time- out!");
		else printf("ERROR!Cannot receive message");
	}
	else if (strlen(buff) > 0){
		buff[ret] = 0;
		printf("receive from server [%s : %d] %s \n", inet_ntoa(serverAddr.sin_addr), ntohs(serverAddr.sin_port), buff);

	}
	closesocket(Client);
	WSACleanup();
	getch();
	return 0;
}