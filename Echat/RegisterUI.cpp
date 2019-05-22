#include "RegisterUI.h"
#include <QMessageBox>

RegisterUI::RegisterUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btn_OK, SIGNAL(clicked()), this, SLOT(btnOK_SLOTS()));			//确定按钮
	connect(ui.btn_Cancel, SIGNAL(clicked()), this, SLOT(btnCancel_SLOTS()));	//取消按钮

}

RegisterUI::~RegisterUI()
{
}

//确定按钮
void RegisterUI::btnOK_SLOTS()
{
	if (ui.name_R->text().isEmpty() || ui.password_R->text().isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请输入名字或密码"));
		return;
	}

	//取得账号和密码
	socketConnect* my_Register = socketConnect::GetIntance();
	my_Register->name_Register = ui.name_R->text();
	QString password = ui.password_R->text();
	my_Register->password_Register = ui.passwordSure_R->text();
	//检查两次密码是否相同
	if (password == my_Register->password_Register)
	{
		//发送名字和密码给服务器
		my_Register->sendMessage(MessageType::RegisterInformation);

		//接收服务器发来的账号
		socketConnect* my_dataReceive = socketConnect::GetIntance();
		connect(my_dataReceive, SIGNAL(registerInformation_Signals(QString)), this, SLOT(registerInformation_Slots(QString)));
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("两次输入的密码不正确！"));
	}
}

//取消按钮
void RegisterUI::btnCancel_SLOTS()
{
	this->reject();
}

//接收账号
void RegisterUI::registerInformation_Slots(QString account)
{
	QMessageBox::information(this, QString::fromLocal8Bit("注册成功！"), QString::fromLocal8Bit("注册成功！你的账号是：\n%1").arg(account));
	this->accept();
}

