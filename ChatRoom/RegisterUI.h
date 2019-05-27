#pragma once

#include <QDialog>
#include "ui_RegisterUI.h"
#include <QNetworkAccessManager>

class RegisterUI : public QDialog
{
	Q_OBJECT

public:
	RegisterUI(QWidget *parent = Q_NULLPTR);
	~RegisterUI();

public:
	QNetworkAccessManager * manager;

private slots:
	void btnOK_Slots();
	void btnCancel_Slots();

	void replyFinished(QNetworkReply *);



private:
	Ui::RegisterUI ui;
};