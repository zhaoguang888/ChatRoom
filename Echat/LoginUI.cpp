#include "LoginUI.h"
#include <QMessageBox>
#include <QKeyEvent>
#include <QDateTime>
#include <QPainter>

LoginUI::LoginUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//登录界面显示端口号
	socketConnect* my_port = socketConnect::GetIntance();
	ui.portLabel->setText(QString::number(my_port->port));	

	connect(ui.btnConnectServer, SIGNAL(clicked()), this, SLOT(btnConnectServer_Slots()));	//按钮：连接服务器
	connect(ui.loginBtn, SIGNAL(clicked()), this, SLOT(btnLogin_Slots()));					//按钮：登录
	connect(ui.registerBtn, SIGNAL(clicked()), this, SLOT(btnRegister_Slots()));			//按钮：注册

	connect(my_port, SIGNAL(receiveCheck(int)), this, SLOT(dataCheck_Slots(int)));	//第三接收：登录检查信息

	/********美化部分******/
	//登录背景图片
	bool ok = titleIMG.load("Resources/loginUI.png");
	//初始化标题
	initTitle();
	//设置皮肤
	this->setStyleSheet(readFile("skin.css"));




	ui.btnConnectServer->setFocus();
}

LoginUI::~LoginUI()
{
}

//连接服务器按钮
void LoginUI::btnConnectServer_Slots()
{
	if (ui.serverIPLineEdit->text().isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请输入 ip 地址"));
		return;
	}

	//在登录界面获取 ip 地址
	socketConnect* my_connect = socketConnect::GetIntance();
	my_connect->ip = ui.serverIPLineEdit->text();	
	//连接服务器
	my_connect->ToConnectHost();	

	if (my_connect->waitForConnected())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("连接服务器成功"));
		ui.btnConnectServer->setEnabled(false);
		ui.loginBtn->setEnabled(true);
		ui.loginBtn->setFocus();
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("连接服务器失败！"));
	}

}
//登录按钮
void LoginUI::btnLogin_Slots()
{
	if (ui.accountLineEdit->text().isEmpty() || ui.passwordLineEdit->text().isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请输入账号或密码！！"));
		return;
	}

	//取得账号和密码
	socketConnect* my_login = socketConnect::GetIntance();
	my_login->loaclAccount = ui.accountLineEdit->text();
	my_login->loaclPassword = ui.passwordLineEdit->text();
	//发送账号、密码等信息给服务器
	my_login->sendMessage(MessageType::UserLogin);
}

//注册按钮
void LoginUI::btnRegister_Slots()
{
	if (ui.loginBtn->isEnabled())
	{
		r = new RegisterUI(this);
		int ok = r->exec();
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请先连接服务器后才注册！"));
	}

}

//第三：登录检查信息
void LoginUI::dataCheck_Slots(int ok)
{
	if (ok == 1)
	{
		qDebug() << QString::fromLocal8Bit("登录成功");
		accept();
	}
	else if (ok == 2)
	{
		qDebug() << QString::fromLocal8Bit("已经登录");
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("你已登录，请关闭程序后再登录！"));

	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("用户名或密码错误！"));
	}
}

//关闭事件
void LoginUI::closeEvent(QCloseEvent * event)
{
	if (ui.loginBtn->isEnabled())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("注意！"), QString::fromLocal8Bit("请使用账号：100 ；密码：abc ；登录后才关闭，谢谢！"));
		event->ignore();
	}
	else
	{
		this->close();
	}


}


/*********************************** 美化 ****************************************/
void LoginUI::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	QRect frameRect = rect();
	frameRect.adjust(1, 1, -1, -1);

	// 画背景和边框
	painter.setPen(QColor(0x66, 0x66, 0x66));
	painter.setBrush(QColor(0xFF, 0xFF, 0xFF));
	painter.drawRoundRect(frameRect, 2, 2);

	// 画标题栏
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
	// 只响应左键
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
	// 只响应左键
	if (event->buttons() & Qt::LeftButton)
	{
		if (isDragging)
		{
			// delta 相对偏移量, 
			QPoint delta = event->globalPos() - startPosition;

			// 新位置：窗体原始位置  + 偏移量
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

//加载styleSheet文件
inline QString LoginUI::readFile(QString filename)
{
	QFile file("skin.css");
	bool ok = file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	return styleSheet;
}

void LoginUI::initTitle()
{
	// 无边框
	setWindowFlags(Qt::FramelessWindowHint);
	// 背景透明
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
