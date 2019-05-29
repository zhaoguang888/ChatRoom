#include "RegisterUI.h"
#include <QMessageBox>
#include <QNetworkReply>

RegisterUI::RegisterUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

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

	//������������Ƿ���ͬ
	if (password == ui.passwordSure_R->text())
	{
		//����http�������ֺ������������
		manager = new QNetworkAccessManager(this);
		connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply *)));

		QString ip = ui.serverIP->text();

		QString url = "http://"+ ip + ":8080/ChatRoomServer/UserRegister?name=" + username + "&password=" + password;
		manager->get(QNetworkRequest(QUrl(url)));

		this->accept();

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
	QMessageBox::information(this, QString::fromLocal8Bit("ע��ɹ���"), QString::fromLocal8Bit("ע��ɹ�������˺��ǣ�\n%1").arg(all));
	reply->deleteLater();
}



