#include "LoginUI.h"
#include <QMessageBox>
#include <QKeyEvent>
#include <QDateTime>
#include <QPainter>

LoginUI::LoginUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//��¼������ʾ�˿ں�
	socketConnect* my_port = socketConnect::GetIntance();
	ui.portLabel->setText(QString::number(my_port->port));	

	connect(ui.btnConnectServer, SIGNAL(clicked()), this, SLOT(btnConnectServer_Slots()));	//��ť�����ӷ�����
	connect(ui.loginBtn, SIGNAL(clicked()), this, SLOT(btnLogin_Slots()));					//��ť����¼
	connect(ui.registerBtn, SIGNAL(clicked()), this, SLOT(btnRegister_Slots()));			//��ť��ע��

	connect(my_port, SIGNAL(receiveCheck(int)), this, SLOT(dataCheck_Slots(int)));	//�������գ���¼�����Ϣ

	/********��������******/
	//��¼����ͼƬ
	bool ok = titleIMG.load("Resources/loginUI.png");
	//��ʼ������
	initTitle();
	//����Ƥ��
	this->setStyleSheet(readFile("skin.css"));




	ui.btnConnectServer->setFocus();
}

LoginUI::~LoginUI()
{
}

//���ӷ�������ť
void LoginUI::btnConnectServer_Slots()
{
	if (ui.serverIPLineEdit->text().isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("������ ip ��ַ"));
		return;
	}

	//�ڵ�¼�����ȡ ip ��ַ
	socketConnect* my_connect = socketConnect::GetIntance();
	my_connect->ip = ui.serverIPLineEdit->text();	
	//���ӷ�����
	my_connect->ToConnectHost();	

	if (my_connect->waitForConnected())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���ӷ������ɹ�"));
		ui.btnConnectServer->setEnabled(false);
		ui.loginBtn->setEnabled(true);
		ui.loginBtn->setFocus();
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���ӷ�����ʧ�ܣ�"));
	}

}
//��¼��ť
void LoginUI::btnLogin_Slots()
{
	if (ui.accountLineEdit->text().isEmpty() || ui.passwordLineEdit->text().isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�������˺Ż����룡��"));
		return;
	}

	//ȡ���˺ź�����
	socketConnect* my_login = socketConnect::GetIntance();
	my_login->loaclAccount = ui.accountLineEdit->text();
	my_login->loaclPassword = ui.passwordLineEdit->text();
	//�����˺š��������Ϣ��������
	my_login->sendMessage(MessageType::UserLogin);
}

//ע�ᰴť
void LoginUI::btnRegister_Slots()
{
	if (ui.loginBtn->isEnabled())
	{
		r = new RegisterUI(this);
		int ok = r->exec();
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�������ӷ��������ע�ᣡ"));
	}

}

//��������¼�����Ϣ
void LoginUI::dataCheck_Slots(int ok)
{
	if (ok == 1)
	{
		qDebug() << QString::fromLocal8Bit("��¼�ɹ�");
		accept();
	}
	else if (ok == 2)
	{
		qDebug() << QString::fromLocal8Bit("�Ѿ���¼");
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���ѵ�¼����رճ�����ٵ�¼��"));

	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�û������������"));
	}
}

//�ر��¼�
void LoginUI::closeEvent(QCloseEvent * event)
{
	if (ui.loginBtn->isEnabled())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("ע�⣡"), QString::fromLocal8Bit("��ʹ���˺ţ�100 �����룺abc ����¼��Źرգ�лл��"));
		event->ignore();
	}
	else
	{
		this->close();
	}


}


/*********************************** ���� ****************************************/
void LoginUI::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	QRect frameRect = rect();
	frameRect.adjust(1, 1, -1, -1);

	// �������ͱ߿�
	painter.setPen(QColor(0x66, 0x66, 0x66));
	painter.setBrush(QColor(0xFF, 0xFF, 0xFF));
	painter.drawRoundRect(frameRect, 2, 2);

	// ��������
	QRect titleRect = frameRect;
	titleRect.setBottom(frameRect.top() + 230);

	QPainterPath path;
	path.addRoundedRect(frameRect.adjusted(1, 1, 0, -1), 2, 2);
	path.intersects(titleRect);
	painter.setClipPath(path);
	painter.drawPixmap(titleRect, titleIMG);

}

void LoginUI::mousePressEvent(QMouseEvent *event)
{
	// ֻ��Ӧ���
	if (event->button() == Qt::LeftButton)
	{
		QRect titleRect = rect();
		titleRect.setBottom(titleRect.top() + 230);

		if (titleRect.contains(event->pos()))
		{
			isDragging = true;
			startPosition = event->globalPos();
			widgetPosition = frameGeometry().topLeft();
		}
	}

	QWidget::mousePressEvent(event);
}

void LoginUI::mouseMoveEvent(QMouseEvent *event)
{
	// ֻ��Ӧ���
	if (event->buttons() & Qt::LeftButton)
	{
		if (isDragging)
		{
			// delta ���ƫ����, 
			QPoint delta = event->globalPos() - startPosition;

			// ��λ�ã�����ԭʼλ��  + ƫ����
			move(widgetPosition + delta);
		}
	}

	QWidget::mouseMoveEvent(event);
}

void LoginUI::mouseReleaseEvent(QMouseEvent * event)
{
	isDragging = false;
	QWidget::mouseReleaseEvent(event);
}

//����styleSheet�ļ�
inline QString LoginUI::readFile(QString filename)
{
	QFile file("skin.css");
	bool ok = file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	return styleSheet;
}

void LoginUI::initTitle()
{
	// �ޱ߿�
	setWindowFlags(Qt::FramelessWindowHint);
	// ����͸��
	setAttribute(Qt::WA_TranslucentBackground);
}

void LoginUI::on_minBtn_clicked()
{
	this->showMinimized();
}


void LoginUI::on_closeBtn_clicked()
{
	this->close();
}
