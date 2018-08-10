// Bui.cpp : Defines the entry point for the console application.
//

#include"stdafx.h"
#include "Model.h"
#include <conio.h>
#include "sqlite3.h"
#include"view.h"
#include "Server.h"
using namespace std;
Controller u = Controller();
void view::send() {
	int chon;
	while (1)
	{
		cout << "-------MENU------\n"
			"1.Gui Tin Nhan\n"
			"2.Ctrl L De Gui\n"
			"3.Exit\n"
			"-----------------------\n";
		cout << "==>Nhap lua chon cua ban: ";
		cin >> chon;
		switch (chon) {
		case 1:
			u.SendMess();
			cout << "-----------------------" << endl;
			break;
		case 2:
			u.SendMess_ctr_l();
			cout << "-----------------------" << endl;
			break;
		case 3:
			return;
		}
	}
}
void view::menu(){
	int choose;
	while (1)
	{

		cout << "-------MENU ------\n"
			"1.Hien thi tin nhan\n"
			"2.Thong tin tin nhan\n"
			"3.Gui tin nhan\n"
			"4.Them ban\n"
			"5.Hien thi danh sach ban\n"
			"6.Chan \n"
			"7.Update \n"

			"9.Thoat\n"
			"-----------------------\n";
		cout << "==>Nhap vao lua chon cua ban: ";
		cin >> choose;
		switch (choose) {
		case 1:
			system("cls");
			u.showmess();
			break;
		case 2:
			system("cls");
			u.ShowMessDetail();
			break;
		case 3:
			system("cls");
			send();
			break;
		case 4:{


				   system("cls");
				   int flag1 = u.AddFriend();
				   if (flag1 == 1)
				   {
					   cout << "them ban thanh cong!!";
				   }
				   break;
		}
		case 5:
			system("cls");
			u.Detail_fr();
			break;
		case 6:
			system("cls");
			u.Block();
			break;
		case 7:
			system("cls");

			break;
		case 9:
			system("cls");
			break;
		default:
			printf("\r\n>> ERROR, Reselect..");
			_getch();
		}
		if (choose == 9)
		{
			break;
		}
	}
}

void view::choice()
{
	int choose = 0;
	do{
		cout << "chon cac chuc nang sau:" << endl;
		cout << "1.Dang nhap" << endl;
		cout << "2.Dang ky" << endl;
		cout << "3.Dang xuat" << endl;
		cout << "4.Thoat" << endl;
		cout << "=Nhap lua chon: ";
		fflush(stdin);
		cin >> choose;
		char buff[] = { choose, '\0' };
		switch (choose){

		case 1:{

				   system("cls");
				  
				   /*int flag = u.Login(); {
					   if (flag == 1)
					   {
						   cout << "Dang nhap thanh cong!!!!" << endl;
						   menu();
					   }*/
				   //}

				   break;
		}
		case 2:{
				   system("cls");
				   

				   /*int flag2 = u.SingUp();
				   if (flag2 == 1)
				   {
					   cout << "Dang ki thanh cong!!!!!!!" << endl;

				   }
				   else cout << "Ngu vl" << endl;*/
				   break;
		}
		case 3:
			system("cls");
			u.SignOut();
			break;
		case 4:
			break;
		default:
			printf("\r\n>>Select:");
			_getch();
		}
		if (choose == 4)
		{
			break;
		}
	} while (1);

}

