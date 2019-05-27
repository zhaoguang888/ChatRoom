#include "ChatRoomUI.h"

ChatRoomUI::ChatRoomUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	chatRoom = SocketConnect::GetIntance(); 
	connect(chatRoom, SIGNAL(noticeAllClient_Signals(QString, QString)), this, SLOT(noticeAllClient_Slots(QString, QString)));
	connect(chatRoom, SIGNAL(updateAllUser_Signals(QString, QString)), this, SLOT(updateAllUser_Slots(QString, QString)));
	connect(chatRoom, SIGNAL(userExit_Signals(QString, QString)), this, SLOT(userExit_Slots(QString, QString)));
}


void ChatRoomUI::noticeAllClient_Slots(QString userEnterMsg, QString thisProgramUserName)
{
	if (userNameSwitch)
	{
		//设置名字
		ui.clientName->setText(thisProgramUserName);
		userNameSwitch = 0;
	}

	//用户进入聊天室信息
	ui.listWidget->setTextColor(Qt::blue);
	ui.listWidget->append(userEnterMsg);

}

void ChatRoomUI::updateAllUser_Slots(QString userAccountName, QString userComputerIP)
{
	bool isEmpty = ui.tableWidget->findItems(userAccountName, Qt::MatchExactly).isEmpty();
	if (isEmpty)
	{
		QTableWidgetItem* updata_n = new QTableWidgetItem(userAccountName);
		QTableWidgetItem* updata_i = new QTableWidgetItem(userComputerIP);
		ui.tableWidget->insertRow(0);
		ui.tableWidget->setItem(0, 0, updata_n);
		ui.tableWidget->setItem(0, 1, updata_i);

		//更新在线用户数
		ui.onlineNumber->setText(QString("%1").arg(ui.tableWidget->rowCount()));
	}
}

void ChatRoomUI::userExit_Slots(QString userExitName, QString userExitMsg)
{
	//用户离开聊天室信息
	ui.listWidget->setTextColor(Qt::gray);
	ui.listWidget->append(userExitMsg);
	ui.listWidget->setTextColor(Qt::black);

	//用户表格信息删除
	int row = ui.tableWidget->findItems(userExitName, Qt::MatchExactly).first()->row();
	ui.tableWidget->removeRow(row);

	//更新在线用户数
	ui.onlineNumber->setText(QString("%1").arg(ui.tableWidget->rowCount()));
}

void ChatRoomUI::closeEvent(QCloseEvent * event)
{
	chatRoom->disconnectFromHost();
}
