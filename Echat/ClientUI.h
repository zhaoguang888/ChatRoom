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
	int name_int = 1; //只显示一次开关

public slots:
	void enterNotice_Slots(QString, QString, QString);			//第一：进入聊天室通知
	void updateBeforeUserInformation_Slots(QString, QString);	//第二：有新用户加入进来时，通知我在线
	void SendBtn_Slots();			//发送按钮
	void receiveChatMessage_Slots(QString);		//聊天消息接收
	void exitInformation_Slots(QString,QString);	//退出信息

	//其他功能槽函数 
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
	bool eventFilter(QObject *target, QEvent *event);	//事件过滤器
private:
	Ui::ClientUIClass ui;
};
