#include "RegisterUI.h"
#include <QMessageBox>

RegisterUI::RegisterUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	serverIP = new QHostAddress();
	port = 8030;


	connect(ui.btn_OK, SIGNAL(clicked()), this, SLOT(btnOK_Slots()));			//确定按钮
	connect(ui.btn_Cancel, SIGNAL(clicked()), this, SLOT(btnCancel_Slots()));	//取消按钮
}

RegisterUI::~RegisterUI()
{
}

//确定按钮
void RegisterUI::btnOK_Slots()
{
	if (ui.name_R->text().isEmpty() || ui.password_R->text().isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请输入名字或密码"));
		return;
	}

	//取得账号和密码
	QString username = ui.name_R->text();
	QString password = ui.password_R->text();
	QString passwordSure = ui.passwordSure_R->text();
	//检查两次密码是否相同
	if (password == passwordSure)
	{
		registerUI = SocketConnect::GetIntance();

		//连接服务器并发送名字和密码给服务器
		if (!this->serverIP->setAddress(ip))
		{
			qDebug() << QString::fromLocal8Bit("服务器地址错误，请重新输入！");
			return;
		}
		registerUI->connectToHost(*serverIP, port);
		if (registerUI->waitForConnected())
		{
			//发送账号和密码给服务器
			registerUI->name_Register = username;
			registerUI->password_Register = password;
			registerUI->sendRequest(RequestTypeEnum::USERREGISTER);
		}
		else
		{
			QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("连接服务器失败！"));
			return;
		}

		connect(registerUI, SIGNAL(userRegister_Signals(QString)), this, SLOT(userRegister_Slots(QString)));

	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("两次输入的密码不正确！"));
	}
}

//取消按钮
void RegisterUI::btnCancel_Slots()
{
	this->reject();
}

void RegisterUI::userRegister_Slots(QString account)
{
	QMessageBox::information(this, QString::fromLocal8Bit("注册成功！"), QString::fromLocal8Bit("注册成功！你的账号是：\n%1").arg(account));
	this->accept();
}



