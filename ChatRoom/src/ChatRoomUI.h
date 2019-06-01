#pragma once

#include <QtWidgets/QWidget>
#include "ui_ChatRoomUI.h"
#include "SocketConnect.h"

class ChatRoomUI : public QWidget
{
	Q_OBJECT

public:
	ChatRoomUI(QWidget *parent = Q_NULLPTR);

private:
	SocketConnect* chatRoom;	//Socket单例

	int userNameSwitch = 1;

private:
	virtual void closeEvent(QCloseEvent *event);	//重写关闭窗口函数

public slots:
	void noticeAllClient_Slots(QString, QString);
	void updateAllUser_Slots(QString, QString);
	void userExit_Slots(QString, QString);
	void sendMessageBtn_Slots();
	void chatMessage_Slots(QString);
protected:
	bool eventFilter(QObject * target, QEvent * event); //事件过滤器，用于按回车键时提交数据

private:
	Ui::ChatRoomUIClass ui;
};
