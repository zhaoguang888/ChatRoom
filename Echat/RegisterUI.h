#pragma once

#include <QDialog>
#include "ui_RegisterUI.h"
#include "socketConnect.h"

class RegisterUI : public QDialog
{
	Q_OBJECT

public:
	RegisterUI(QWidget *parent = Q_NULLPTR);
	~RegisterUI();

private slots:
	void btnOK_SLOTS();
	void btnCancel_SLOTS();

	void registerInformation_Slots(QString);	//Ω” ’’À∫≈

private:
	Ui::RegisterUI ui;
};
