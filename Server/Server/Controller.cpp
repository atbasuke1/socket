
#include "Server.h"
#include"view.h"
#include "stdafx.h"
#include "Model.h"
#include "sqlite3.h"
#include <iostream>


Controller::Controller()
{
}
void Controller::ConnectDB() {
	m.ConnectDB();
}
void Controller::DisConnectDB() {
	m.DisConnectDB();
}
int Controller::Login() {
	 m.Login();
}
int Controller::SingUp() {
	 m.SingUp();
}
void Controller::SignOut() {
	m.SignOut();
}
int Controller::AddFriend() {
	return m.AddFriend();
}
int Controller::Block() {
	return m.Block();
}

int Controller::SendMess() {
	return m.SendMess();
}
int Controller::SendMess_ctr_l() {
	return m.SendMess_ctr_l();
}
int Controller::ShowMessDetail() {
	return m.ShowMessDetail();
}

void Controller::Detail_fr() {
	m.Detail_fr();
}
int Controller::showmess(){
	return m.showmess();
}

void Controller::Error() {
	m.Error();
}
void Controller::setNguoidung(string s) {
	m.setNguoidung(s);
}
string Controller::getNguoidung() {
	return m.getNguoidung();
}
Controller::~Controller()
{
}
