#pragma once

#include <QTcpSocket>
#include <QHostAddress>

enum RequestTypeEnum
{
	USERLOGIN, USERLOGINCHECK, UPDATEALLUSER, NOTICEALLCLIENT, USEREXIT, CHATMESSAGE, USERREGISTER
};

class SocketConnect : public QTcpSocket
{
	Q_OBJECT

//单例模式
public:
	static SocketConnect *GetIntance();
private:
	static SocketConnect *instance;

public:
	int statusValidate;	//登录验证的状态：0--验证失败；1--验证成功；2--用户已登录

	//发送到服务器的信息
	QString loaclComputerName;	//电脑名
	QString loaclComputerIP;	//ip地址
	QString UserAccount;		//账号
	QString UserPassword;		//密码
	int loginStatus;			//登录状态

	QString chatMessage_Request;	//要发送聊天信息
	QString chatMessage_Response;

	//接收服务器的响应信息
	QString thisProgramUserName;	//此程序的用户的唯一名字

	QString userEnterMsg;	//进入聊天室的消息
	QString userAccountName;//其他用户名字
	QString userComputerIP;	//其他用户ip地址

	QString userExitName;	//用户退出名字
	QString userExitMsg;	//用户退出消息

	//注册消息
	QString name_Register;		//注册名字
	QString password_Register;	//注册密码
	QString account_Register;	//服务器返回的账号


private:
	QString getloaclComputerIP();	//本地ip地址获取函数

//函数
public:
	void sendRequest(RequestTypeEnum);	//发送请求

	void sendUserLogin();			//请求登录
	void sendChatMessage();			//发送聊天消息
	void sendRegisterMessage();		//注册信息

private slots:
	void dataReceived_Slot();		//数据来到的发出的 readyRead() 信号

signals:
	void userLoginCheck_Signals(int);		//登录验证的状态：0--验证失败；1--验证成功；2--用户已登录
signals:
	void noticeAllClient_Signals(QString, QString);	//有新用户进来时进行通知所有用户
signals:
	void updateAllUser_Signals(QString, QString);	//更新在线用户
signals:
	void userExit_Signals(QString, QString);	//退出信息
signals:
	void ChatMessage_Signals(QString);	//聊天消息
signals:
	void userRegister_Signals(QString);	//注册消息


public:
	SocketConnect(QObject *parent);
	~SocketConnect();
};
