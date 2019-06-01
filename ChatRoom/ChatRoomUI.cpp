#include "ChatRoomUI.h"
#include <QMessageBox>
#include <QKeyEvent>

ChatRoomUI::ChatRoomUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//��ȡSocket�ĵ���
	chatRoom = SocketConnect::GetIntance(); 
	connect(chatRoom, SIGNAL(noticeAllClient_Signals(QString, QString)), this, SLOT(noticeAllClient_Slots(QString, QString)));
	connect(chatRoom, SIGNAL(updateAllUser_Signals(QString, QString)), this, SLOT(updateAllUser_Slots(QString, QString)));
	connect(chatRoom, SIGNAL(userExit_Signals(QString, QString)), this, SLOT(userExit_Slots(QString, QString)));

	ui.sendLineEdit->setFocusPolicy(Qt::StrongFocus);
	ui.sendLineEdit->setFocus();
	ui.sendLineEdit->installEventFilter(this);  //��������Զ�������eventFilter����
	connect(ui.sendBtn, SIGNAL(clicked()), this, SLOT(sendMessageBtn_Slots()));						//������Ϣ
	connect(chatRoom, SIGNAL(chatMessage_Signals(QString)), this, SLOT(chatMessage_Slots(QString)));//������Ϣ

}

//���շ����������ĵ�¼����������Ϣ�Ĳۺ���
void ChatRoomUI::noticeAllClient_Slots(QString thisProgramUserName, QString userEnterMsg)
{
	if (userNameSwitch)
	{
		//��������
		ui.clientName->setText(thisProgramUserName);
		userNameSwitch = 0;
	}
	//�û�������������Ϣ
	ui.listWidget->setTextColor(Qt::blue);
	ui.listWidget->append(userEnterMsg);
}

//���շ��������µ����������û���Ϣ�Ĳۺ���
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

		//���������û���
		ui.onlineNumber->setText(QString("%1").arg(ui.tableWidget->rowCount()));
	}
}

//���շ�����������������Ϣ�Ĳۺ���
void ChatRoomUI::chatMessage_Slots(QString message)
{
	ui.listWidget->setTextColor(Qt::black);
	ui.listWidget->append(message);
}


//������Ϣ
void ChatRoomUI::sendMessageBtn_Slots()
{
	if (ui.sendLineEdit->toPlainText() == "")
	{
		QMessageBox::information(this, "ERROR", QString::fromLocal8Bit("���������ݣ�"));
		return;
	}

	if (chatRoom->waitForConnected())
	{
		//����������Ϣ
		chatRoom->chatMessage_Request = ui.sendLineEdit->toPlainText();
		chatRoom->sendRequest(RequestTypeEnum::CHATMESSAGE);
	}

	ui.sendLineEdit->clear();
	ui.sendLineEdit->setFocus();
}

//�رմ�����д����
void ChatRoomUI::closeEvent(QCloseEvent * event)
{
	if (chatRoom->waitForConnected())
	{
		//�û��˳�����-----�޸����ݿ�����
		chatRoom->sendRequest(RequestTypeEnum::USEREXITHANDLE);
	}
	QMessageBox::information(this, QString::fromLocal8Bit("information"), QString::fromLocal8Bit("�˳��ɹ���"));
	chatRoom->disconnectFromHost();
}

//���շ����������ݿ������޸ĺ󴫸��ͻ��˵���Ϣ
void ChatRoomUI::userExit_Slots(QString userExitName, QString userExitMsg)
{
	//�û��뿪��������Ϣ
	ui.listWidget->setTextColor(Qt::gray);
	ui.listWidget->append(userExitMsg);
	ui.listWidget->setTextColor(Qt::black);

	//�û������Ϣɾ��
	int row = ui.tableWidget->findItems(userExitName, Qt::MatchExactly).first()->row();
	ui.tableWidget->removeRow(row);

	//���������û���
	ui.onlineNumber->setText(QString("%1").arg(ui.tableWidget->rowCount()));
}


//�س���ť�¼�
bool ChatRoomUI::eventFilter(QObject *target, QEvent *event)
{
	if (target == ui.sendLineEdit)
	{
		if (event->type() == QEvent::KeyPress)	//�س���
		{
			QKeyEvent *k = static_cast<QKeyEvent *>(event);
			if (k->key() == Qt::Key_Return)
			{
				if (ui.sendBtn->isEnabled())
				{
					sendMessageBtn_Slots();
					return true;
				}

			}
		}
	}
	return QWidget::eventFilter(target, event);
}

