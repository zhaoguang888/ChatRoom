#include "socketConnect.h"
#include <QDateTime>
#include <QHostInfo>
#include <QDataStream>

//����ģʽ
socketConnect* socketConnect::instance = NULL;
socketConnect* socketConnect::GetIntance()
{
	if (instance == NULL)
	{
		instance = new socketConnect(0);
	}
	return instance;
}

//���캯��
socketConnect::socketConnect(QObject *parent)
	: QTcpSocket(parent)
{
	port = 8010;		//���ö˿ں�
	ip = "0";
	serverIP = new QHostAddress();

	connect(this, SIGNAL(connected()), this, SLOT(connectSuccess_Slot()));		//���ӳɹ��󷢳� connected() �ź�
	connect(this, SIGNAL(readyRead()), this, SLOT(dataReceived_Slot()));		//���������ķ����� readyRead() �ź�
	connect(this, SIGNAL(disconnected()), this, SLOT(disConnected_Slot()));		//�Ͽ����Ӻ󷢴�� disconnected() �ź�

}

socketConnect::~socketConnect()
{
}


//���ӷ�����
bool socketConnect::ToConnectHost()
{
	if (!serverIP->setAddress(ip))
	{
		qDebug() << QString::fromLocal8Bit("��������ַ�������������룡");
		return false;
	}

	this->connectToHost(*serverIP, port);
	if (this->waitForConnected())
	{
		qDebug() << QString::fromLocal8Bit("���ӷ������ɹ�����һ�����ӣ�����");
		return true;
	}
	else
	{
		qDebug() << QString::fromLocal8Bit("���ӷ�����ʧ�ܣ�");
		return false;
	}
}

//������Ϣ����
void socketConnect::sendMessage(MessageType type)
{
	switch (type)
	{
	case UserLogin:
		//��¼��ť
		sendLoginInfo();
		break;
	case updateBeforeUserInformation:
		//���������������û�����
		sendOneselfInformation();
		break;
	case Information:
		//����������Ϣ
		sendChatMessage();
		break;
	case RegisterInformation:
		//ע����Ϣ
		sendRegisterInformation();
		break;
	default:
		break;
	}
}

//������Ϣ���ͣ��������ղۺ���
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
			//��һ���գ�����������֪ͨ
			in >> noticeEnter >> userClientName >> ipAddress;
			emit enterNotice(noticeEnter, userClientName, ipAddress);
			break;
		case updateBeforeUserInformation:
			//�ڶ����գ������û��������ʱ��֪ͨ������
			in >> updateBefore_Name >> uodateBefore_ip;
			updateBeforeUserInformation_Signals(updateBefore_Name, uodateBefore_ip);
			break;
		case receiveServerCheck:
			//�������գ���¼�����Ϣ
			in >> check;
			emit receiveCheck(check);	
			break;
		case Information:
			//������Ϣ����
			in >> chatMessage_Receive;
			emit receiveChatMessage(chatMessage_Receive);
			break;
		case RegisterInformation:
			//ע����Ϣ
			in >> registerAccount;
			emit registerInformation_Signals(registerAccount);
			break;
		case UserExit:
			//�뿪��Ϣ
			in >> exitMessage >> exitName;
			exitInformation_Signal(exitMessage,exitName);
			break;
		default:
			break;
		}
	}
}

//���͵�¼��Ϣ
void socketConnect::sendLoginInfo()
{
	//��¼����
	MessageType enumLogin = UserLogin;
	//����ip��ַ
	localIP = getLocalIP();		
	//��¼״̬
	loginStatus = 0;			

	//ʹ��QByteArray�������ݴ�Ҫ���͵����ݣ�ʹ�� QDataStream ��Ҫ���͵����� д��QByteArray�����С�
	QByteArray messageData;
	QDataStream out(&messageData, QIODevice::WriteOnly);
	//д���¼����         ������      ����ip��ַ   �����˺�   ��������    ������¼״̬
	out << enumLogin << loaclHostName << localIP << loaclAccount << loaclPassword << loginStatus;

	int length = write(messageData);
	if (length != messageData.length())
	{
		qDebug() << QString::fromLocal8Bit("���ݷ��ʹ���");
		return ;
	}
	return ;
}

//����������Ϣ
void socketConnect::sendChatMessage()
{
	MessageType enumInformation = Information;
	QByteArray messageData;
	QDataStream out(&messageData, QIODevice::WriteOnly);

	out << enumInformation << chatMessage_Send << loaclAccount;
	int length = write(messageData);
	if (length != messageData.length())
	{
		qDebug() << QString::fromLocal8Bit("���ݷ��ʹ���");
		return;
	}
	return;
}

//��ȡ����IP��ַ
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


//�����û���ʱ�������Լ�����Ϣ
void socketConnect::sendOneselfInformation()
{
	MessageType enumOneselfInformation = updateBeforeUserInformation;

	QByteArray data;
	QDataStream out(&data, QIODevice::WriteOnly);
	out << enumOneselfInformation << nameID << ipID;

	int length = write(data);
	if (length != data.length())
	{
		qDebug() << QString::fromLocal8Bit("���ݷ��ʹ���");
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
		qDebug() << QString::fromLocal8Bit("���ݷ��ʹ���");
		return;
	}
	return;
}

//���ӳɹ��󷢳� connected() �źŹ����Ĳۺ���
void socketConnect::connectSuccess_Slot()
{
	qDebug() << QString::fromLocal8Bit("�ɹ����ӷ����������Ĳۺ���");
}
//�Ͽ����Ӻ󷢳��� disconnected() �źŹ����Ĳۺ���
void socketConnect::disConnected_Slot()
{
	qDebug() << QString::fromLocal8Bit("�Ͽ�����");
}
