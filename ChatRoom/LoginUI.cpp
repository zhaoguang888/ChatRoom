#include "LoginUI.h"
#include <QMessageBox>

LoginUI::LoginUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	port = 8030;
	ip = "0.0.0.0";
	serverIP = new QHostAddress();
	ui.portLabel->setText(QString::number(port));

	login = SocketConnect::GetIntance();	//��ȡSocket�ĵ���

	ui.loginBtn->setFocus();
	connect(ui.registerBtn, SIGNAL(clicked()), this, SLOT(btnRegister_Slots()));			//ע�ᰴť
	connect(ui.loginBtn, SIGNAL(clicked()), this, SLOT(btnLogin_Slots()));					//��¼��ť

	connect(login, SIGNAL(userLoginCheck_Signals(int)), this, SLOT(userLoginCheck_Slots(int)));	//��¼�����Ϣ
}
LoginUI::~LoginUI()
{
}

//ע�ᰴť
void LoginUI::btnRegister_Slots()
{
	registerUI = new RegisterUI(this);
	registerUI->ip = ui.serverIPLineEdit->text();
	int ok = registerUI->exec();
}

//��¼��ť
void LoginUI::btnLogin_Slots()
{
	if (ui.accountLineEdit->text().isEmpty() || ui.passwordLineEdit->text().isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�������˺Ż����룡��"));
		return;
	}
	if (ui.serverIPLineEdit->text().isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("������ ip ��ַ"));
		return;
	}


	//ȡ���˺š����롢������ip��ַ
	login->UserAccount = ui.accountLineEdit->text();
	login->UserPassword = ui.passwordLineEdit->text();
	ip = ui.serverIPLineEdit->text();

	//���ӷ��������ҷ����˺š��������Ϣ��������
	if (!this->serverIP->setAddress(ip))
	{
		qDebug() << QString::fromLocal8Bit("��������ַ�������������룡");
		return;
	}
	login->connectToHost(*serverIP, port);
	if (login->waitForConnected())
	{
		//�����˺ź������������
		login->sendRequest(RequestTypeEnum::USERLOGIN);
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���ӷ�����ʧ�ܣ�"));
		ui.loginBtn->setFocus();
		return;
	}
}

void LoginUI::userLoginCheck_Slots(int ok)
{
	if (ok == 1)
	{
		qDebug() << QString::fromLocal8Bit("��¼�ɹ�");
		accept();
	}
	else if (ok == 2)
	{
		qDebug() << QString::fromLocal8Bit("�Ѿ���¼");
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���ѵ�¼����رճ�����ٵ�¼��"));

	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�û������������"));
	}
}
