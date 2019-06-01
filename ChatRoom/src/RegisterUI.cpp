#include "RegisterUI.h"
#include <QMessageBox>

RegisterUI::RegisterUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	socketConnect = SocketConnect::GetIntance(); //��ȡSocket�ĵ���

	connect(ui.btn_OK, SIGNAL(clicked()), this, SLOT(btnOK_Slots()));			//ȷ����ť
	connect(ui.btn_Cancel, SIGNAL(clicked()), this, SLOT(btnCancel_Slots()));	//ȡ����ť
	connect(socketConnect, SIGNAL(userRegister_Signals(QString)), this, SLOT(userRegister_Slots(QString)));	//�����˺Ųۺ���
}

RegisterUI::~RegisterUI()
{
}

//ȷ����ť
void RegisterUI::btnOK_Slots()
{
	//��������Ƿ�Ϊ��
	if (ui.name_R->text().isEmpty() || ui.password_R->text().isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���������ֻ�����"));
		return;
	}

	//ȡ���˺ź�����
	QString username = ui.name_R->text();
	QString password = ui.password_R->text();

	//������������Ƿ���ͬ
	if (password == ui.passwordSure_R->text())
	{
		socketConnect->userName_Register = username;
		socketConnect->userPassword_Register = password;

		//���ӷ��������������ݸ�������
		if (!socketConnect->hostAddress->setAddress(socketConnect->serverIP))
		{
			return;
		}
		socketConnect->connectToHost(*socketConnect->hostAddress, socketConnect->port);
		if (socketConnect->waitForConnected())
		{
			socketConnect->sendRequest(RequestTypeEnum::USERREGISTER);
		}
		else
		{
			QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���ӷ�����ʧ�ܣ�"));
			return;
		}
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("������������벻��ȷ��"));
		return;
	}
}

//ȡ����ť
void RegisterUI::btnCancel_Slots()
{
	this->reject();
}

//�����˺Ųۺ���
void RegisterUI::userRegister_Slots(QString account)
{
	QMessageBox::information(this, QString::fromLocal8Bit("ע��ɹ���"), QString::fromLocal8Bit("ע��ɹ�������˺��ǣ�\n%1").arg(account));
	socketConnect->disconnectFromHost();
	this->accept();
}




