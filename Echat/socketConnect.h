#pragma once

#include <QTcpSocket>
#include <QHostAddress>

enum MessageType
{
	//用户登录   聊天消息   用户退出     登录验证         通知所有客户端   通知之前登录的用户更新自己的信息   注册信息
	UserLogin, Information, UserExit, receiveServerCheck, noticeAnyClient, updateBeforeUserInformation, RegisterInformation
};

class socketConnect : public QTcpSocket
{
	Q_OBJECT

public:
	int port;	//端口号，内部设置
	QString ip;	//登录界面的服务器ip地址

	//要发送的登录信息
	QString loaclAccount;	//本机账号
	QString loaclPassword;	//本机密码

	QString noticeEnter;	//一条用户进来的消息
	QString userClientName;	//用户的名字
	QString ipAddress;	//IP地址

	QString updateBefore_Name;	//新用户加入进来的名字
	QString uodateBefore_ip;	//新用户加入进来的ip地址

	QString nameID;	//本客户端自己独有的名字
	QString ipID;	//本客户端自己独有的ip地址

	int check;	//登录验证的状态：0--验证失败；1--验证成功；2--用户已登录

	QString chatMessage_Receive;	//从服务器接收来的聊天信息

	//注册功能
	QString name_Register;		//注册名字
	QString password_Register;	//注册密码
	QString account_Register;	//服务器返回的账号

private:
	QHostAddress *serverIP;

	//要发送的登录信息
	QString loaclHostName;	//本机名
	QString getLocalIP();		//本地ip地址获取函数
	QString localIP;		//本机ip地址
	int loginStatus;		//本机登录状态

public:
	QString chatMessage_Send;	//要发送聊天信息
	QString exitMessage;	//退出信息
	QString exitName;		//退出消息的名字
	QString registerAccount;	//注册用户，服务器发来的账号

	bool ToConnectHost();	//连接服务器函数
	void sendMessage(MessageType);	//发送消息
	void sendLoginInfo();	//发送登录信息
	void sendChatMessage();	//发送聊天消息
	void sendOneselfInformation();	//有新用户来时告诉他自己的信息
	//注册信息
	void sendRegisterInformation();

private slots:
	void connectSuccess_Slot();	//连接成功后发出 connected() 信号
	void dataReceived_Slot();	//数据来到的发出的 readyRead() 信号
	void disConnected_Slot();	//断开连接后发错的 disconnected() 信号

signals:
	void receiveChatMessage(QString);	//接收聊天消息
signals:
	void receiveCheck(int);		//接收验证消息：登录成功，已登录，账号或密码错误
signals:
	void enterNotice(QString,QString,QString);					//第一接收：进入聊天室通知
signals:
	void updateBeforeUserInformation_Signals(QString, QString);	//第二接收：有新用户加入进来时，通知我在线
signals:
	void exitInformation_Signal(QString,QString);	//退出信息
signals:
	void registerInformation_Signals(QString);	//注册功能


//单例模式
private:
	socketConnect(QObject *parent);
	~socketConnect();
public:
	static socketConnect* GetIntance();
private:
	static socketConnect* instance;
};
