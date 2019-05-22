#include "RegisterUI.h"
#include <QMessageBox>

RegisterUI::RegisterUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btn_OK, SIGNAL(clicked()), this, SLOT(btnOK_SLOTS()));			//ȷ����ť
	connect(ui.btn_Cancel, SIGNAL(clicked()), this, SLOT(btnCancel_SLOTS()));	//ȡ����ť

}

RegisterUI::~RegisterUI()
{
}

//ȷ����ť
void RegisterUI::btnOK_SLOTS()
{
	if (ui.name_R->text().isEmpty() || ui.password_R->text().isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���������ֻ�����"));
		return;
	}

	//ȡ���˺ź�����
	socketConnect* my_Register = socketConnect::GetIntance();
	my_Register->name_Register = ui.name_R->text();
	QString password = ui.password_R->text();
	my_Register->password_Register = ui.passwordSure_R->text();
	//������������Ƿ���ͬ
	if (password == my_Register->password_Register)
	{
		//�������ֺ������������
		my_Register->sendMessage(MessageType::RegisterInformation);

		//���շ������������˺�
		socketConnect* my_dataReceive = socketConnect::GetIntance();
		connect(my_dataReceive, SIGNAL(registerInformation_Signals(QString)), this, SLOT(registerInformation_Slots(QString)));
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("������������벻��ȷ��"));
	}
}

//ȡ����ť
void RegisterUI::btnCancel_SLOTS()
{
	this->reject();
}

//�����˺�
void RegisterUI::registerInformation_Slots(QString account)
{
	QMessageBox::information(this, QString::fromLocal8Bit("ע��ɹ���"), QString::fromLocal8Bit("ע��ɹ�������˺��ǣ�\n%1").arg(account));
	this->accept();
}

