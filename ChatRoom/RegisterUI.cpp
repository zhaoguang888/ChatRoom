#include "RegisterUI.h"
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
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
	QString passwordSure = ui.passwordSure_R->text();
	//������������Ƿ���ͬ
	if (password == passwordSure)
	{
		//�������ֺ������������
		manager = new QNetworkAccessManager(this);
		connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));
		manager->get(QNetworkRequest(QUrl("http://www.zhaoguangcloud.cn:8080/Servlet/Hello")));

	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("������������벻��ȷ��"));
	}
}
void RegisterUI::replyFinished(QNetworkReply *reply)
{
	QString all = reply->readAll();
	QMessageBox::information(this, QString::fromLocal8Bit("ע��ɹ���"), QString::fromLocal8Bit("ע��ɹ�������˺��ǣ�\n%1").arg(all));
	reply->deleteLater();
	this->accept();
}

//ȡ����ť
void RegisterUI::btnCancel_Slots()
{
	this->reject();
}


