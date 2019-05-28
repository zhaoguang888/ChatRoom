#include "RegisterUI.h"
#include <QMessageBox>

RegisterUI::RegisterUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	serverIP = new QHostAddress();
	port = 8030;


	connect(ui.btn_OK, SIGNAL(clicked()), this, SLOT(btnOK_Slots()));			//ȷ����ť
	connect(ui.btn_Cancel, SIGNAL(clicked()), this, SLOT(btnCancel_Slots()));	//ȡ����ť
}

RegisterUI::~RegisterUI()
{
}

//ȷ����ť
void RegisterUI::btnOK_Slots()
{
	if (ui.name_R->text().isEmpty() || ui.password_R->text().isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���������ֻ�����"));
		return;
	}

	//ȡ���˺ź�����
	QString username = ui.name_R->text();
	QString password = ui.password_R->text();
	QString passwordSure = ui.passwordSure_R->text();
	//������������Ƿ���ͬ
	if (password == passwordSure)
	{
		registerUI = SocketConnect::GetIntance();

		//���ӷ��������������ֺ������������
		if (!this->serverIP->setAddress(ip))
		{
			qDebug() << QString::fromLocal8Bit("��������ַ�������������룡");
			return;
		}
		registerUI->connectToHost(*serverIP, port);
		if (registerUI->waitForConnected())
		{
			//�����˺ź������������
			registerUI->name_Register = username;
			registerUI->password_Register = password;
			registerUI->sendRequest(RequestTypeEnum::USERREGISTER);
		}
		else
		{
			QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���ӷ�����ʧ�ܣ�"));
			return;
		}

		connect(registerUI, SIGNAL(userRegister_Signals(QString)), this, SLOT(userRegister_Slots(QString)));

	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("������������벻��ȷ��"));
	}
}

//ȡ����ť
void RegisterUI::btnCancel_Slots()
{
	this->reject();
}

void RegisterUI::userRegister_Slots(QString account)
{
	QMessageBox::information(this, QString::fromLocal8Bit("ע��ɹ���"), QString::fromLocal8Bit("ע��ɹ�������˺��ǣ�\n%1").arg(account));
	this->accept();
}



