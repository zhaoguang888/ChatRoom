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
	SocketConnect *registerUI;	//Socket����

	int port;	//�˿ں�
	QString ip;	//������ip��ַ
	QHostAddress *serverIP;//������ip��ַ����

private:


private slots:
	void btnOK_Slots();
	void btnCancel_Slots();

	void userRegister_Slots(QString);	//�����˺�



private:
	Ui::RegisterUI ui;
};
