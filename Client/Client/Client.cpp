#include"stdafx.h"
#include <iostream>
#include <winsock2.h>
#include "Client.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include<WS2tcpip.h>
#include <conio.h>

#define SERVER_ADDR "127.0.0.1"
#define PORT 5500
#define BUFF_SIZE 2048

int client::client_recv(void){
	WSADATA wsaData;
	WORD wVersion = MAKEWORD(2, 2);
	if (WSAStartup(wVersion, &wsaData))
		printf("Version is not supported\n");
	
	SOCKET Client;
	Client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	int tv = 10000;
	setsockopt(Client, SOL_SOCKET, SO_RCVTIMEO, (const char*)(&tv), sizeof(int));
	sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
	if (connect(Client, (sockaddr *)&serverAddr, sizeof(serverAddr))){
		printf("Error! Cannot connect server. %d", WSAGetLastError());
		_getch();
		return 0;
	}
	printf("connected sever!\n");
	while (1){
		char buff[BUFF_SIZE];
		int ret, serverAddrLen = sizeof(serverAddr);
		do{
			printf("Send to server: ");
			gets_s(buff, BUFF_SIZE);
			ret = send(Client, buff, strlen(buff), 0);
			if (ret == SOCKET_ERROR)
				printf("Error! cannot send message. ");
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
			_strupr_s(buff, BUFF_SIZE);
		} while (strcmp(buff, "bye") != 0);
		
	}
	closesocket(Client);
	WSACleanup();
	_getch();
	return 0;
}