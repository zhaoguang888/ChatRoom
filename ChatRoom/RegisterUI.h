#pragma once

#include <QDialog>
#include "ui_RegisterUI.h"
#include "SocketConnect.h"
#include <QtNetwork>

class RegisterUI : public QDialog
{
	Q_OBJECT

public:
	RegisterUI(QWidget *parent = Q_NULLPTR);
	~RegisterUI();

private:
	SocketConnect *socketConnect;	//Socket单例

private slots:
	void btnOK_Slots();		//确定按钮
	void btnCancel_Slots();	//取消按钮
	void userRegister_Slots(QString);	//接收账号

private:
	Ui::RegisterUI ui;
};
