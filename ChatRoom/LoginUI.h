#pragma once

#include <QDialog>
#include "ui_LoginUI.h"
#include "RegisterUI.h"
#include "SocketConnect.h"

class LoginUI : public QDialog
{
	Q_OBJECT

public:
	LoginUI(QWidget *parent = Q_NULLPTR);
	~LoginUI();

public:
	SocketConnect* login;		//Socket单例
	RegisterUI* registerUI;		//注册界面

	int port;	//端口号
	QString ip;	//服务器ip地址
	QHostAddress *serverIP;//服务器ip地址对象

private slots:
	void btnRegister_Slots();	//注册按钮
	void btnLogin_Slots();		//登录按钮
	void userLoginCheck_Slots(int);	//登录检查信息



private:
	Ui::LoginUI ui;
};
