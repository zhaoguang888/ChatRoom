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

private:
	SocketConnect *socketConnect;	//Socket单例
	RegisterUI* registerUI;			//注册界面

private slots:
	void btnRegister_Slots();	//注册按钮
	void btnLogin_Slots();		//登录按钮
	void userLoginCheck_Slots(int);	//登录检查信息



private:
	Ui::LoginUI ui;
};
