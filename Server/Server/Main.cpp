#include <iostream>
#include <string>
#include <ctime>
#include "sqlite3.h"
#include "Model.h"
#include <stdlib.h>
#include "stdafx.h"
#include <Windows.h>
#include "View.h"
#include "Server.h"
using namespace std;
int choice_m = 0;
view view1;
server server5;
HANDLE HThread1;

DWORD WINAPI tcpip_recv(LPVOID arg){
	server5.server_recv();

	return 0;
}

int main()
{

	HANDLE hThread2 = CreateThread(NULL, 0, tcpip_recv, NULL, 0, NULL);
	WaitForSingleObject(hThread2, INFINITE);
	CloseHandle(hThread2);
	system("pause");
	return 0;
}