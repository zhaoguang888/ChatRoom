#pragma once

#include <QTcpSocket>
#include <QHostAddress>

enum RequestType
{
	userLogin, userLoginCheck, updateAllUser, noticeAllClient, userExit, chatMessage
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

	//接收服务器的响应信息
	QString thisProgramUserName;	//启动一个程序的用户名字

	QString userEnterMsg;	//进入聊天室的消息
	QString userAccountName;//其他用户名字
	QString userComputerIP;	//其他用户ip地址

	QString userExitName;	//用户退出名字
	QString userExitMsg;	//用户退出消息



private:
	QString getloaclComputerIP();	//本地ip地址获取函数

//函数
public:
	void sendRequest(RequestType);	//发送请求
	void sendUserLogin();			//请求登录

private slots:
	void dataReceived_Slot();		//数据来到的发出的 readyRead() 信号

signals:
	void userLoginCheck_Signals(int);		//登录验证的状态：0--验证失败；1--验证成功；2--用户已登录
signals:
	void noticeAllClient_Signals(QString, QString);	//有新用户进来时进行通知所有用户
signals:
	void updateAllUser_Signals(QString, QString);	//更新在线用户
signals:
	void userExit_Signals(QString, QString);	//更新在线用户


public:
	SocketConnect(QObject *parent);
	~SocketConnect();
};
