#include "socketConnect.h"
#include <QDateTime>
#include <QHostInfo>
#include <QDataStream>

//单例模式
socketConnect* socketConnect::instance = NULL;
socketConnect* socketConnect::GetIntance()
{
	if (instance == NULL)
	{
		instance = new socketConnect(0);
	}
	return instance;
}

//构造函数
socketConnect::socketConnect(QObject *parent)
	: QTcpSocket(parent)
{
	port = 8010;		//设置端口号
	ip = "0";
	serverIP = new QHostAddress();

	connect(this, SIGNAL(connected()), this, SLOT(connectSuccess_Slot()));		//连接成功后发出 connected() 信号
	connect(this, SIGNAL(readyRead()), this, SLOT(dataReceived_Slot()));		//数据来到的发出的 readyRead() 信号
	connect(this, SIGNAL(disconnected()), this, SLOT(disConnected_Slot()));		//断开连接后发错的 disconnected() 信号

}

socketConnect::~socketConnect()
{
}


//连接服务器
bool socketConnect::ToConnectHost()
{
	if (!serverIP->setAddress(ip))
	{
		qDebug() << QString::fromLocal8Bit("服务器地址错误，请重新输入！");
		return false;
	}

	this->connectToHost(*serverIP, port);
	if (this->waitForConnected())
	{
		qDebug() << QString::fromLocal8Bit("连接服务器成功！第一次连接！！！");
		return true;
	}
	else
	{
		qDebug() << QString::fromLocal8Bit("连接服务器失败！");
		return false;
	}
}

//发送消息类型
void socketConnect::sendMessage(MessageType type)
{
	switch (type)
	{
	case UserLogin:
		//登录按钮
		sendLoginInfo();
		break;
	case updateBeforeUserInformation:
		//告诉他们我是新用户加入
		sendOneselfInformation();
		break;
	case Information:
		//发送聊天消息
		sendChatMessage();
		break;
	case RegisterInformation:
		//注册信息
		sendRegisterInformation();
		break;
	default:
		break;
	}
}

//接收消息类型：主动接收槽函数
void socketConnect::dataReceived_Slot()
{
	while (bytesAvailable() > 0)
	{
		int length = bytesAvailable();
		QDataStream in(this);

		int type;
		in >> type;
		switch (type)
		{
		case noticeAnyClient:
			//第一接收：进入聊天室通知
			in >> noticeEnter >> userClientName >> ipAddress;
			emit enterNotice(noticeEnter, userClientName, ipAddress);
			break;
		case updateBeforeUserInformation:
			//第二接收：有新用户加入进来时，通知我在线
			in >> updateBefore_Name >> uodateBefore_ip;
			updateBeforeUserInformation_Signals(updateBefore_Name, uodateBefore_ip);
			break;
		case receiveServerCheck:
			//第三接收：登录检查信息
			in >> check;
			emit receiveCheck(check);	
			break;
		case Information:
			//聊天信息数据
			in >> chatMessage_Receive;
			emit receiveChatMessage(chatMessage_Receive);
			break;
		case RegisterInformation:
			//注册信息
			in >> registerAccount;
			emit registerInformation_Signals(registerAccount);
			break;
		case UserExit:
			//离开消息
			in >> exitMessage >> exitName;
			exitInformation_Signal(exitMessage,exitName);
			break;
		default:
			break;
		}
	}
}

//发送登录信息
void socketConnect::sendLoginInfo()
{
	//登录类型
	MessageType enumLogin = UserLogin;
	//本机ip地址
	localIP = getLocalIP();		
	//登录状态
	loginStatus = 0;			

	//使用QByteArray对象来暂存要发送的数据，使用 QDataStream 将要发送的数据 写入QByteArray对象中。
	QByteArray messageData;
	QDataStream out(&messageData, QIODevice::WriteOnly);
	//写入登录类型         本机名      本机ip地址   本机账号   本机密码    本机登录状态
	out << enumLogin << loaclHostName << localIP << loaclAccount << loaclPassword << loginStatus;

	int length = write(messageData);
	if (length != messageData.length())
	{
		qDebug() << QString::fromLocal8Bit("数据发送错误");
		return ;
	}
	return ;
}

//发送聊天消息
void socketConnect::sendChatMessage()
{
	MessageType enumInformation = Information;
	QByteArray messageData;
	QDataStream out(&messageData, QIODevice::WriteOnly);

	out << enumInformation << chatMessage_Send << loaclAccount;
	int length = write(messageData);
	if (length != messageData.length())
	{
		qDebug() << QString::fromLocal8Bit("数据发送错误");
		return;
	}
	return;
}

//获取本地IP地址
QString socketConnect::getLocalIP()
{
	loaclHostName = QHostInfo::localHostName();
	QHostInfo hostInformation = QHostInfo::fromName(loaclHostName);
	QList<QHostAddress> clientList = hostInformation.addresses();

	QString ipTemp;
	foreach(QHostAddress address, clientList)
	{
		qDebug() << address.toString();
		if (address.protocol() == QAbstractSocket::IPv4Protocol)
		{
			ipTemp = address.toString();
			continue;
		}
	}
	return ipTemp;
}


//有新用户来时告诉他自己的信息
void socketConnect::sendOneselfInformation()
{
	MessageType enumOneselfInformation = updateBeforeUserInformation;

	QByteArray data;
	QDataStream out(&data, QIODevice::WriteOnly);
	out << enumOneselfInformation << nameID << ipID;

	int length = write(data);
	if (length != data.length())
	{
		qDebug() << QString::fromLocal8Bit("数据发送错误");
		return;
	}
	return;
}

void socketConnect::sendRegisterInformation()
{
	MessageType enumRegisterInformation = RegisterInformation;

	QByteArray data;
	QDataStream out(&data, QIODevice::WriteOnly);
	out << enumRegisterInformation << name_Register << password_Register;

	int length = write(data);
	if (length != data.length())
	{
		qDebug() << QString::fromLocal8Bit("数据发送错误");
		return;
	}
	return;
}

//连接成功后发出 connected() 信号关联的槽函数
void socketConnect::connectSuccess_Slot()
{
	qDebug() << QString::fromLocal8Bit("成功连接服务器发出的槽函数");
}
//断开连接后发出的 disconnected() 信号关联的槽函数
void socketConnect::disConnected_Slot()
{
	qDebug() << QString::fromLocal8Bit("断开连接");
}
