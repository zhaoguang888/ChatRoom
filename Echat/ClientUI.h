#pragma once

#include <QtWidgets/QWidget>
#include "ui_ClientUI.h"
#include "socketConnect.h"
#include <QTextCharFormat>

class ClientUI : public QWidget
{
	Q_OBJECT
public:
	ClientUI(QWidget *parent = Q_NULLPTR);

private:
	int name_int = 1; //ֻ��ʾһ�ο���

public slots:
	void enterNotice_Slots(QString, QString, QString);			//��һ������������֪ͨ
	void updateBeforeUserInformation_Slots(QString, QString);	//�ڶ��������û��������ʱ��֪ͨ������
	void SendBtn_Slots();			//���Ͱ�ť
	void receiveChatMessage_Slots(QString);		//������Ϣ����
	void exitInformation_Slots(QString,QString);	//�˳���Ϣ

	//�������ܲۺ��� 
	void on_fontCbx_currentFontChanged(const QFont&);
	void on_sizeCbx_currentIndexChanged(const QString&);
	void on_boldTBtn_clicked(bool);
	void on_italicTBtn_clicked(bool);
	void on_underlineTBtn_clicked(bool);
	void on_colorTBtn_clicked();
	void on_sendFileTBtn_clicked();

private slots:
	void curFmtChanged(const QTextCharFormat&);
private:
	QColor color;
	virtual void closeEvent(QCloseEvent *event);
protected:
	bool eventFilter(QObject *target, QEvent *event);	//�¼�������
private:
	Ui::ClientUIClass ui;
};
