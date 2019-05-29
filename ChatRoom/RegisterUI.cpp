#include "RegisterUI.h"
#include <QMessageBox>
#include <QNetworkReply>

RegisterUI::RegisterUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

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

	//检查两次密码是否相同
	if (password == ui.passwordSure_R->text())
	{
		//利用http发送名字和密码给服务器
		manager = new QNetworkAccessManager(this);
		connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply *)));

		QString ip = ui.serverIP->text();

		QString url = "http://"+ ip + ":8080/ChatRoomServer/UserRegister?name=" + username + "&password=" + password;
		manager->get(QNetworkRequest(QUrl(url)));

		this->accept();

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
	QMessageBox::information(this, QString::fromLocal8Bit("注册成功！"), QString::fromLocal8Bit("注册成功！你的账号是：\n%1").arg(all));
	reply->deleteLater();
}



