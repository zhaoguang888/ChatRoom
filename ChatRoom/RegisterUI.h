#pragma once

#include <QDialog>
#include "ui_RegisterUI.h"
#include "SocketConnect.h"

class RegisterUI : public QDialog
{
	Q_OBJECT

public:
	RegisterUI(QWidget *parent = Q_NULLPTR);
	~RegisterUI();


public:
	SocketConnect *registerUI;	//Socket单例

	int port;	//端口号
	QString ip;	//服务器ip地址
	QHostAddress *serverIP;//服务器ip地址对象

private:


private slots:
	void btnOK_Slots();
	void btnCancel_Slots();

	void userRegister_Slots(QString);	//接收账号



private:
	Ui::RegisterUI ui;
};
