#include "RegisterUI.h"
#include <QMessageBox>
#include <QNetworkReply>

RegisterUI::RegisterUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

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
		//����http�������ֺ������������
		manager = new QNetworkAccessManager(this);
		connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply *)));
		manager->get(QNetworkRequest(QUrl("http://localhost:8080/ChatRoomServer/UserRegister?name=%E6%A2%85%E8%A5%BF&password=123")));

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

void RegisterUI::replyFinished(QNetworkReply * reply)
{
	QString all = reply->readAll();
	QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), all);
	reply->deleteLater();
}



