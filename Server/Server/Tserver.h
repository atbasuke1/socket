#include "stdafx.h"
#include <winsock2.h>
#include<WS2tcpip.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#pragma comment (lib,"ws2_32.lib")

#define SERVER_ADDR "127.0.0.1"
#define PORT 5500
#define BUFF_SIZE 2048
void processData(char *, char *);
int Receive(SOCKET, char *, int, int);
int Send(SOCKET, char *, int, int);