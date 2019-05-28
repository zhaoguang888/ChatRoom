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

	login = SocketConnect::GetIntance();	//获取Socket的单例

	ui.loginBtn->setFocus();
	connect(ui.registerBtn, SIGNAL(clicked()), this, SLOT(btnRegister_Slots()));			//注册按钮
	connect(ui.loginBtn, SIGNAL(clicked()), this, SLOT(btnLogin_Slots()));					//登录按钮

	connect(login, SIGNAL(userLoginCheck_Signals(int)), this, SLOT(userLoginCheck_Slots(int)));	//登录检查信息
}
LoginUI::~LoginUI()
{
}

//注册按钮
void LoginUI::btnRegister_Slots()
{
	registerUI = new RegisterUI(this);
	registerUI->ip = ui.serverIPLineEdit->text();
	int ok = registerUI->exec();
}

//登录按钮
void LoginUI::btnLogin_Slots()
{
	if (ui.accountLineEdit->text().isEmpty() || ui.passwordLineEdit->text().isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请输入账号或密码！！"));
		return;
	}
	if (ui.serverIPLineEdit->text().isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请输入 ip 地址"));
		return;
	}


	//取得账号、密码、服务器ip地址
	login->UserAccount = ui.accountLineEdit->text();
	login->UserPassword = ui.passwordLineEdit->text();
	ip = ui.serverIPLineEdit->text();

	//连接服务器并且发送账号、密码等信息给服务器
	if (!this->serverIP->setAddress(ip))
	{
		qDebug() << QString::fromLocal8Bit("服务器地址错误，请重新输入！");
		return;
	}
	login->connectToHost(*serverIP, port);
	if (login->waitForConnected())
	{
		//发送账号和密码给服务器
		login->sendRequest(RequestTypeEnum::USERLOGIN);
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("连接服务器失败！"));
		ui.loginBtn->setFocus();
		return;
	}
}

void LoginUI::userLoginCheck_Slots(int ok)
{
	if (ok == 1)
	{
		qDebug() << QString::fromLocal8Bit("登录成功");
		accept();
	}
	else if (ok == 2)
	{
		qDebug() << QString::fromLocal8Bit("已经登录");
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("你已登录，请关闭程序后再登录！"));

	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("用户名或密码错误！"));
	}
}
