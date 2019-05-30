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
	SocketConnect *socketConnect;	//Socket����
	RegisterUI* registerUI;			//ע�����

private slots:
	void btnRegister_Slots();	//ע�ᰴť
	void btnLogin_Slots();		//��¼��ť
	void userLoginCheck_Slots(int);	//��¼�����Ϣ



private:
	Ui::LoginUI ui;
};
