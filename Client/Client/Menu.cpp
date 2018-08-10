#include <iostream>
#include <string>
#include <ctime>
#include"sqlite3.h"
#include"view.h"
#include "Model.h"
#include <stdlib.h>
#include <Windows.h>
#include "Client.h"
view view1;
using namespace std;
int choice_m = 0;

client client2;
DWORD WINAPI tcpip_recv(LPVOID arg){


	client2.client_recv();
	return 0;
}

int main()
{
	view1.menu();
	HANDLE hThread1 = CreateThread(NULL, 0, tcpip_recv, NULL, 0, NULL);

	WaitForSingleObject(hThread1, INFINITE);
	CloseHandle(hThread1);


	system("pause");
	return 0;
}