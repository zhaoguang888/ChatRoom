#include "ClientUI.h"
#include <QMessageBox>
#include <QHostInfo>
#include <QKeyEvent>
#include <QDateTime>
#include <QColorDialog>

ClientUI::ClientUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.sendLineEdit->setFocusPolicy(Qt::StrongFocus);
	ui.sendLineEdit->setFocus();
	ui.sendLineEdit->installEventFilter(this);  //设置完后自动调用其eventFilter函数

	connect(ui.sendBtn, SIGNAL(clicked()), this, SLOT(SendBtn_Slots())); //发送按钮

	socketConnect* my_dataReceive = socketConnect::GetIntance();
	//第一：进入聊天室通知
	connect(my_dataReceive, SIGNAL(enterNotice(QString,QString,QString)), this, SLOT(enterNotice_Slots(QString,QString,QString)));
	//第二：有新用户加入进来时，通知我在线
	connect(my_dataReceive, SIGNAL(updateBeforeUserInformation_Signals(QString, QString)), this, SLOT(updateBeforeUserInformation_Slots(QString, QString)));
	//聊天消息接收
	connect(my_dataReceive, SIGNAL(receiveChatMessage(QString)), this, SLOT(receiveChatMessage_Slots(QString)));	
	//退出信息
	connect(my_dataReceive, SIGNAL(exitInformation_Signal(QString,QString)), this, SLOT(exitInformation_Slots(QString,QString)));

	//字体切换
	connect(ui.sendLineEdit, SIGNAL(currentCharFormatChanged(QTextCharFormat)), this, SLOT(curFmtChanged(const QTextCharFormat)));
}

//发送按钮
void ClientUI::SendBtn_Slots()
{
	if (ui.sendLineEdit->toPlainText() == "")
	{
		QMessageBox::information(this, "ERROR", QString::fromLocal8Bit("请输入内容！"));
		return ;
	}

	socketConnect* my_send = socketConnect::GetIntance();
	if (my_send->waitForConnected())
	{
		//发送聊天消息
		my_send->chatMessage_Send = ui.sendLineEdit->toPlainText();
		my_send->sendMessage(MessageType::Information);
	}

	ui.sendLineEdit->clear();
	ui.sendLineEdit->setFocus();
}

//聊天消息接收
void ClientUI::receiveChatMessage_Slots(QString msg)
{
	ui.listWidget->setTextColor(Qt::black);
	ui.listWidget->append(msg);
}

//第一：进入聊天室通知
void ClientUI::enterNotice_Slots(QString str,QString name, QString ipAddress)
{
	if (name_int)
	{
		//设置名字
		ui.clientName->setText(name);
		//设置新用户的名字和ip地址
		socketConnect* my_sendOneself = socketConnect::GetIntance();
		my_sendOneself->nameID = name;
		my_sendOneself->ipID = ipAddress;

		QTableWidgetItem* n = new QTableWidgetItem(name);
		QTableWidgetItem* i = new QTableWidgetItem(ipAddress);
		ui.tableWidget->insertRow(0);
		ui.tableWidget->setItem(0, 0, n);
		ui.tableWidget->setItem(0, 1, i);

		//告诉他们我是新用户加入
		my_sendOneself->sendMessage(MessageType::updateBeforeUserInformation);

		//更新在线用户数
		ui.onlineNumber->setText(QString("%1").arg(ui.tableWidget->rowCount()));

		name_int = 0;
	}
	//用户进入聊天室信息
	ui.listWidget->setTextColor(Qt::blue);
	ui.listWidget->append(str);
}

//第二：有新用户加入进来时，通知我在线
void ClientUI::updateBeforeUserInformation_Slots(QString updateBefor_name, QString updateBefore_ip)
{
	bool isEmpty = ui.tableWidget->findItems(updateBefor_name, Qt::MatchExactly).isEmpty();
	if (isEmpty)
	{
		QTableWidgetItem* updata_n = new QTableWidgetItem(updateBefor_name);
		QTableWidgetItem* updata_i = new QTableWidgetItem(updateBefore_ip);
		ui.tableWidget->insertRow(0);
		ui.tableWidget->setItem(0, 0, updata_n);
		ui.tableWidget->setItem(0, 1, updata_i);

		socketConnect* my_sendOneself = socketConnect::GetIntance();
		my_sendOneself->sendMessage(MessageType::updateBeforeUserInformation);

		//更新在线用户数
		ui.onlineNumber->setText(QString("%1").arg(ui.tableWidget->rowCount()));
	}
}

//退出信息
void ClientUI::exitInformation_Slots(QString msg,QString en)
{
	//用户离开聊天室信息
	ui.listWidget->setTextColor(Qt::gray);
	ui.listWidget->append(msg);
	ui.listWidget->setTextColor(Qt::black);

	//用户表格信息删除
	int row = ui.tableWidget->findItems(en, Qt::MatchExactly).first()->row();
	ui.tableWidget->removeRow(row);

	//更新在线用户数
	ui.onlineNumber->setText(QString("%1").arg(ui.tableWidget->rowCount()));
}

//关闭窗口重写事件
void ClientUI::closeEvent(QCloseEvent * event)
{
	socketConnect* my_disConnect = socketConnect::GetIntance();
	my_disConnect->disconnectFromHost();
}

//回车按钮事件
bool ClientUI::eventFilter(QObject *target, QEvent *event)
{
	if (target == ui.sendLineEdit)
	{
		if (event->type() == QEvent::KeyPress)	//回车键
		{
			QKeyEvent *k = static_cast<QKeyEvent *>(event);
			if (k->key() == Qt::Key_Return)
			{
				if (ui.sendBtn->isEnabled())
				{
					SendBtn_Slots();
					return true;
				}

			}
		}
	}
	return QWidget::eventFilter(target, event);
}







/**************************************** 其他功能 *******************************************/
//字体
void ClientUI::on_fontCbx_currentFontChanged(const QFont & f)
{
	ui.sendLineEdit->setCurrentFont(f);
	ui.sendLineEdit->setFocus();
}

//字体大小
void ClientUI::on_sizeCbx_currentIndexChanged(const QString &arg1)
{
	ui.sendLineEdit->setFontPointSize(arg1.toDouble());
	ui.sendLineEdit->setFocus();
}

//粗体
void ClientUI::on_boldTBtn_clicked(bool checked)
{
	if (checked)
	{
		ui.sendLineEdit->setFontWeight(QFont::Bold);
	}
	else
	{
		ui.sendLineEdit->setFontWeight(QFont::Normal);
		ui.sendFileTBtn->setFocus();
	}
}

//斜体
void ClientUI::on_italicTBtn_clicked(bool checked)
{
	ui.sendLineEdit->setFontItalic(checked);
	ui.sendLineEdit->setFocus();
}

//下划线
void ClientUI::on_underlineTBtn_clicked(bool checked)
{
	ui.sendLineEdit->setFontUnderline(checked);
	ui.sendLineEdit->setFocus();
}

//颜色
void ClientUI::on_colorTBtn_clicked()
{
	color = QColorDialog::getColor(color, this);
	if (color.isValid())
	{
		ui.sendLineEdit->setTextColor(color);
		ui.sendLineEdit->setFocus();
	}
}

//发送文件
void ClientUI::on_sendFileTBtn_clicked()
{
	QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("此功能还未完善"));
}

//字体切换
void ClientUI::curFmtChanged(const QTextCharFormat &fmt)
{
	ui.fontCbx->setCurrentFont(fmt.font());
	if (fmt.fontPointSize() < 8)
	{
		ui.sizeCbx->setCurrentIndex(4);
	}
	else
	{
		ui.sizeCbx->setCurrentIndex(ui.sizeCbx->findText(QString::number(fmt.fontPointSize())));
	}
	ui.boldTBtn->setChecked(fmt.font().bold());
	ui.italicTBtn->setChecked(fmt.font().italic());
	ui.underlineTBtn->setChecked(fmt.font().underline());
	color = fmt.foreground().color();
}