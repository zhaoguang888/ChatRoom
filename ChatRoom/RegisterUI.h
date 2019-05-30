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
	SocketConnect *socketConnect;	//Socket����

private slots:
	void btnOK_Slots();		//ȷ����ť
	void btnCancel_Slots();	//ȡ����ť
	void userRegister_Slots(QString);	//�����˺�

private:
	Ui::RegisterUI ui;
};
