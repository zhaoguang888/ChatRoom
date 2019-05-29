#include "SocketConnect.h"
#include <QHostInfo>
#include <QDataStream>

//单例模式
SocketConnect *SocketConnect::instance = NULL;
SocketConnect *SocketConnect::GetIntance()
{
	if (instance == NULL)
	{
		instance = new SocketConnect(0);
	}
	return instance;
}

//构造函数
SocketConnect::SocketConnect(QObject *parent)
	: QTcpSocket(parent)
{
	connect(this, SIGNAL(readyRead()), this, SLOT(dataReceived_Slot()));	//接收数据
	
}
SocketConnect::~SocketConnect()
{
}


//请求到服务器的类型
void SocketConnect::sendRequest(RequestTypeEnum type)
{
	switch (type)
	{
	case USERLOGIN:
		sendUserLogin();
		break;
	case CHATMESSAGE:
		sendChatMessage();
		break;
	default:
		break;
	}
}
//接收服务器的响应
void SocketConnect::dataReceived_Slot()
{
	while (bytesAvailable() > 0)
	{
		int length = bytesAvailable();
		QDataStream in(this);

		int type;
		in >> type;
		switch (type)
		{
		case USERLOGINCHECK:
			in >> statusValidate;
			emit userLoginCheck_Signals(statusValidate);
			break;
		case NOTICEALLCLIENT:
			in >> thisProgramUserName >> userEnterMsg;
			emit noticeAllClient_Signals(userEnterMsg, thisProgramUserName);
			break;
		case UPDATEALLUSER:
			in >> userAccountName >> userComputerIP;
			emit updateAllUser_Signals(userAccountName, userComputerIP);
			break;
		case USEREXIT:
			in >> userExitName >> userExitMsg;
			emit userExit_Signals(userExitName, userExitMsg);
			break;
		case CHATMESSAGE:
			in >> chatMessage_Response;
			emit ChatMessage_Signals(chatMessage_Response);
			break;
		default:
			break;
		}
	}
}

void SocketConnect::sendUserLogin()
{
	loginStatus = 0;
	loaclComputerName = QHostInfo::localHostName();
	loaclComputerIP = getloaclComputerIP();
	qDebug() << loginStatus << loaclComputerName << loaclComputerIP;

	//使用QByteArray对象来暂存要发送的数据，使用 QDataStream 将要发送的数据 写入QByteArray对象中。
	QByteArray messageData;
	QDataStream out(&messageData, QIODevice::WriteOnly);
	//		登录类型         本机名      本机ip地址   本机账号   本机密码    本机登录状态
	out << USERLOGIN << loaclComputerName << loaclComputerIP << UserAccount << UserPassword << loginStatus;

	int length = write(messageData);
	if (length != messageData.length())
	{
		qDebug() << QString::fromLocal8Bit("数据发送错误");
		return;
	}
}

void SocketConnect::sendChatMessage()
{
	QByteArray messageData;
	QDataStream out(&messageData, QIODevice::WriteOnly);
	out << CHATMESSAGE << UserAccount << chatMessage_Request;

	int length = write(messageData);
	if (length != messageData.length())
	{
		qDebug() << QString::fromLocal8Bit("数据发送错误");
		return;
	}
}

QString SocketConnect::getloaclComputerIP()
{

	QHostInfo hostInformation = QHostInfo::fromName(loaclComputerName);
	QList<QHostAddress> clientList = hostInformation.addresses();

	QString ip;
	for (int i = 0; i < clientList.length(); i++)
	{
		qDebug() << clientList[i].toString();
		if (clientList[i].protocol() == QAbstractSocket::IPv4Protocol)
		{
			ip = clientList[i].toString();
		}
	}

	return ip;
}



