#include "SocketConnect.h"
#include <QHostInfo>
#include <QDataStream>

//����ģʽ
SocketConnect *SocketConnect::instance = NULL;
SocketConnect *SocketConnect::GetIntance()
{
	if (instance == NULL)
	{
		instance = new SocketConnect(0);
	}
	return instance;
}

//���캯��
SocketConnect::SocketConnect(QObject *parent)
	: QTcpSocket(parent)
{
	connect(this, SIGNAL(readyRead()), this, SLOT(dataReceived_Slot()));	//��������
	
}
SocketConnect::~SocketConnect()
{
}


//���󵽷�����������
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
//���շ���������Ӧ
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

	//ʹ��QByteArray�������ݴ�Ҫ���͵����ݣ�ʹ�� QDataStream ��Ҫ���͵����� д��QByteArray�����С�
	QByteArray messageData;
	QDataStream out(&messageData, QIODevice::WriteOnly);
	//		��¼����         ������      ����ip��ַ   �����˺�   ��������    ������¼״̬
	out << USERLOGIN << loaclComputerName << loaclComputerIP << UserAccount << UserPassword << loginStatus;

	int length = write(messageData);
	if (length != messageData.length())
	{
		qDebug() << QString::fromLocal8Bit("���ݷ��ʹ���");
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
		qDebug() << QString::fromLocal8Bit("���ݷ��ʹ���");
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



