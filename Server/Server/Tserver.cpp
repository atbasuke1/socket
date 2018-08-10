
#include "stdafx.h"
#include "Server.h"
#include"Model.h"
#include <winsock2.h>
#include<WS2tcpip.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define SERVER_PORT 5500
#define BUFF_SIZE 2048
#define SERVER_ADDR "127.0.0.1"
#define PORT 5500




void processData(char *, char *);
int Receive(SOCKET, char *, int, int);
int Send(SOCKET, char *, int, int);

int server::server_recv(void)
{
	//Step 1: Initiate WinSock
		WSADATA wsaData;
		WORD wVersion = MAKEWORD(2, 2);
		if (WSAStartup(wVersion, &wsaData))
			printf("Version is not supported\n");

		//Step 2: Construct socket	
		SOCKET listenSock;
		listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	

		//Step 3: Bind address to socket
		sockaddr_in serverAddr;
		serverAddr.sin_family = AF_INET;
		serverAddr.sin_port = htons(PORT);
		serverAddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

		if (bind(listenSock, (sockaddr *)&serverAddr, sizeof(serverAddr)))
		{
			printf("Error! Cannot bind this address.");
			_getch();
			return 0;
		}

		//Step 4: Listen request from client
		if (listen(listenSock, 10)) {
			printf("Error! Cannot listen.");
			_getch();
			return 0;
		}

	printf("Server started!\n");
	//Step 5:
	sockaddr_in clientAddr;
	char buff[BUFF_SIZE];
	int ret, clientAddrLen = sizeof(clientAddr);
	while(1){	
		SOCKET connSock;
		//accept request
		
		connSock = accept(listenSock, (sockaddr *)&clientAddr, &clientAddrLen);
		//recevie message from client
		do{
			ret = recv(connSock, buff, BUFF_SIZE, 0);
			if (ret == SOCKET_ERROR){
				printf("\nError! Cannot poll sockets: %d", WSAGetLastError());
				}
			else if (strlen(buff) > 0){
				buff[ret] = 0;
				printf("receive from client[%s : %d] %s \n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port), buff);
			//Echo to client
				ret = send(connSock, buff, strlen(buff), 0);
				if (ret == SOCKET_ERROR)
					printf("Error: %", WSAGetLastError);
		
				}
			_strupr_s(buff, BUFF_SIZE);
		} while (strcmp(buff, "bye") != 0);
		closesocket(connSock);
	}
	closesocket(listenSock);
	
	WSACleanup();
	return 0;
}

/* The processData function copies the input string to output
* @param in Pointer to input string
* @param out Pointer to output string
* @return No return value
*/
void processData(char *in, char *out) {
	memcpy(out, in, BUFF_SIZE);
}

///* The recv() wrapper function */
int Receive(SOCKET s, char *buff, int size, int flags) {
	int n;

	n = recv(s, buff, size, flags);
	if (n == SOCKET_ERROR)
		printf("Error: %", WSAGetLastError());

	return n;
}

/* The send() wrapper function*/
int Send(SOCKET s, char *buff, int size, int flags) {
	int n;

	n = send(s, buff, size, flags);
	if (n == SOCKET_ERROR)
		printf("Error: %", WSAGetLastError());

	return n;
}
