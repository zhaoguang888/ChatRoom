#include "LoginUI.h"
#include <QMessageBox>

LoginUI::LoginUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	socketConnect = SocketConnect::GetIntance(); //��ȡSocket�ĵ���
	socketConnect->port = 8030;			//���ö˿ں�
	socketConnect->serverIP = "0.0.0.0";//��ʼ��������ip��ַ
	ui.portLabel->setText(QString::number(socketConnect->port));
	ui.loginBtn->setFocus();


	connect(ui.registerBtn, SIGNAL(clicked()), this, SLOT(btnRegister_Slots()));			//ע�ᰴť
	connect(ui.loginBtn, SIGNAL(clicked()), this, SLOT(btnLogin_Slots()));					//��¼��ť
	connect(socketConnect, SIGNAL(userLoginCheck_Signals(int)), this, SLOT(userLoginCheck_Slots(int)));	//���յ�¼�����Ϣ
}
LoginUI::~LoginUI()
{
}

//ע�ᰴť
void LoginUI::btnRegister_Slots()
{
	//��ȡ������ip��ַ
	socketConnect->serverIP = ui.serverIPLineEdit->text();

	registerUI = new RegisterUI(this);
	int ok = registerUI->exec();
}

//��¼��ť
void LoginUI::btnLogin_Slots()
{
	//��ȡ������ip��ַ
	socketConnect->serverIP = ui.serverIPLineEdit->text();

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

	//��ȡ�˺š�����
	socketConnect->userAccount = ui.accountLineEdit->text();
	socketConnect->userPassword = ui.passwordLineEdit->text();

	//���ӷ��������������ݸ�������
	if (!socketConnect->hostAddress->setAddress(socketConnect->serverIP))
	{
		return;
	}
	socketConnect->connectToHost(*socketConnect->hostAddress, socketConnect->port);
	if (socketConnect->waitForConnected())
	{
		socketConnect->sendRequest(RequestTypeEnum::USERLOGIN);
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���ӷ�����ʧ�ܣ�"));
		ui.loginBtn->setFocus();
		return;
	}
}

//��¼�����Ϣ
void LoginUI::userLoginCheck_Slots(int ok)
{
	if (ok == 1)
	{
		qDebug() << QString::fromLocal8Bit("��¼�ɹ�");
		accept();
	}
	else if (ok == 2)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���ѵ�¼����رճ�����ٵ�¼��"));
		socketConnect->disconnectFromHost();
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�û������������"));
		socketConnect->disconnectFromHost();
	}
}
