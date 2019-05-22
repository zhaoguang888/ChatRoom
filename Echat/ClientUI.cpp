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
	ui.sendLineEdit->installEventFilter(this);  //��������Զ�������eventFilter����

	connect(ui.sendBtn, SIGNAL(clicked()), this, SLOT(SendBtn_Slots())); //���Ͱ�ť

	socketConnect* my_dataReceive = socketConnect::GetIntance();
	//��һ������������֪ͨ
	connect(my_dataReceive, SIGNAL(enterNotice(QString,QString,QString)), this, SLOT(enterNotice_Slots(QString,QString,QString)));
	//�ڶ��������û��������ʱ��֪ͨ������
	connect(my_dataReceive, SIGNAL(updateBeforeUserInformation_Signals(QString, QString)), this, SLOT(updateBeforeUserInformation_Slots(QString, QString)));
	//������Ϣ����
	connect(my_dataReceive, SIGNAL(receiveChatMessage(QString)), this, SLOT(receiveChatMessage_Slots(QString)));	
	//�˳���Ϣ
	connect(my_dataReceive, SIGNAL(exitInformation_Signal(QString,QString)), this, SLOT(exitInformation_Slots(QString,QString)));

	//�����л�
	connect(ui.sendLineEdit, SIGNAL(currentCharFormatChanged(QTextCharFormat)), this, SLOT(curFmtChanged(const QTextCharFormat)));
}

//���Ͱ�ť
void ClientUI::SendBtn_Slots()
{
	if (ui.sendLineEdit->toPlainText() == "")
	{
		QMessageBox::information(this, "ERROR", QString::fromLocal8Bit("���������ݣ�"));
		return ;
	}

	socketConnect* my_send = socketConnect::GetIntance();
	if (my_send->waitForConnected())
	{
		//����������Ϣ
		my_send->chatMessage_Send = ui.sendLineEdit->toPlainText();
		my_send->sendMessage(MessageType::Information);
	}

	ui.sendLineEdit->clear();
	ui.sendLineEdit->setFocus();
}

//������Ϣ����
void ClientUI::receiveChatMessage_Slots(QString msg)
{
	ui.listWidget->setTextColor(Qt::black);
	ui.listWidget->append(msg);
}

//��һ������������֪ͨ
void ClientUI::enterNotice_Slots(QString str,QString name, QString ipAddress)
{
	if (name_int)
	{
		//��������
		ui.clientName->setText(name);
		//�������û������ֺ�ip��ַ
		socketConnect* my_sendOneself = socketConnect::GetIntance();
		my_sendOneself->nameID = name;
		my_sendOneself->ipID = ipAddress;

		QTableWidgetItem* n = new QTableWidgetItem(name);
		QTableWidgetItem* i = new QTableWidgetItem(ipAddress);
		ui.tableWidget->insertRow(0);
		ui.tableWidget->setItem(0, 0, n);
		ui.tableWidget->setItem(0, 1, i);

		//���������������û�����
		my_sendOneself->sendMessage(MessageType::updateBeforeUserInformation);

		//���������û���
		ui.onlineNumber->setText(QString("%1").arg(ui.tableWidget->rowCount()));

		name_int = 0;
	}
	//�û�������������Ϣ
	ui.listWidget->setTextColor(Qt::blue);
	ui.listWidget->append(str);
}

//�ڶ��������û��������ʱ��֪ͨ������
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

		//���������û���
		ui.onlineNumber->setText(QString("%1").arg(ui.tableWidget->rowCount()));
	}
}

//�˳���Ϣ
void ClientUI::exitInformation_Slots(QString msg,QString en)
{
	//�û��뿪��������Ϣ
	ui.listWidget->setTextColor(Qt::gray);
	ui.listWidget->append(msg);
	ui.listWidget->setTextColor(Qt::black);

	//�û������Ϣɾ��
	int row = ui.tableWidget->findItems(en, Qt::MatchExactly).first()->row();
	ui.tableWidget->removeRow(row);

	//���������û���
	ui.onlineNumber->setText(QString("%1").arg(ui.tableWidget->rowCount()));
}

//�رմ�����д�¼�
void ClientUI::closeEvent(QCloseEvent * event)
{
	socketConnect* my_disConnect = socketConnect::GetIntance();
	my_disConnect->disconnectFromHost();
}

//�س���ť�¼�
bool ClientUI::eventFilter(QObject *target, QEvent *event)
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
					SendBtn_Slots();
					return true;
				}

			}
		}
	}
	return QWidget::eventFilter(target, event);
}







/**************************************** �������� *******************************************/
//����
void ClientUI::on_fontCbx_currentFontChanged(const QFont & f)
{
	ui.sendLineEdit->setCurrentFont(f);
	ui.sendLineEdit->setFocus();
}

//�����С
void ClientUI::on_sizeCbx_currentIndexChanged(const QString &arg1)
{
	ui.sendLineEdit->setFontPointSize(arg1.toDouble());
	ui.sendLineEdit->setFocus();
}

//����
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

//б��
void ClientUI::on_italicTBtn_clicked(bool checked)
{
	ui.sendLineEdit->setFontItalic(checked);
	ui.sendLineEdit->setFocus();
}

//�»���
void ClientUI::on_underlineTBtn_clicked(bool checked)
{
	ui.sendLineEdit->setFontUnderline(checked);
	ui.sendLineEdit->setFocus();
}

//��ɫ
void ClientUI::on_colorTBtn_clicked()
{
	color = QColorDialog::getColor(color, this);
	if (color.isValid())
	{
		ui.sendLineEdit->setTextColor(color);
		ui.sendLineEdit->setFocus();
	}
}

//�����ļ�
void ClientUI::on_sendFileTBtn_clicked()
{
	QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�˹��ܻ�δ����"));
}

//�����л�
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