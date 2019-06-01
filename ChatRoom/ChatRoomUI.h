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
	SocketConnect* chatRoom;	//Socket����

	int userNameSwitch = 1;

private:
	virtual void closeEvent(QCloseEvent *event);	//��д�رմ��ں���

public slots:
	void noticeAllClient_Slots(QString, QString);
	void updateAllUser_Slots(QString, QString);
	void userExit_Slots(QString, QString);
	void sendMessageBtn_Slots();
	void chatMessage_Slots(QString);
protected:
	bool eventFilter(QObject * target, QEvent * event); //�¼������������ڰ��س���ʱ�ύ����

private:
	Ui::ChatRoomUIClass ui;
};
