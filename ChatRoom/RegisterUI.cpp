#include "RegisterUI.h"
#include <QMessageBox>
#include <QNetworkReply>

RegisterUI::RegisterUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

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
		//利用http发送名字和密码给服务器
		manager = new QNetworkAccessManager(this);
		connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply *)));
		manager->get(QNetworkRequest(QUrl("http://localhost:8080/ChatRoomServer/UserRegister?name=%E6%A2%85%E8%A5%BF&password=123")));

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

void RegisterUI::replyFinished(QNetworkReply * reply)
{
	QString all = reply->readAll();
	QMessageBox::information(this, QString::fromLocal8Bit("提示"), all);
	reply->deleteLater();
}



