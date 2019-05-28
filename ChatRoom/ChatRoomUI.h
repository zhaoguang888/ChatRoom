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
	SocketConnect* chatRoom;
	int userNameSwitch = 1;

private:
	virtual void closeEvent(QCloseEvent *event);	//��д�رմ��ں���

public slots:
	void noticeAllClient_Slots(QString, QString);
	void updateAllUser_Slots(QString, QString);
	void userExit_Slots(QString, QString);

	void sendMessageBtn_Slots();
	bool eventFilter(QObject * target, QEvent * event); //�¼�������
	void ChatMessage_Slots(QString);

private:
	Ui::ChatRoomUIClass ui;
};
