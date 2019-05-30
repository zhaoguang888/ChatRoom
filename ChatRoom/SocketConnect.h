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

//����ģʽ
public:
	static SocketConnect *GetIntance();
private:
	static SocketConnect *instance;

public:
	//��¼���������������Ϣ
	int port;			//�˿ں�
	QString serverIP;	//������ip��ַ
	QHostAddress *hostAddress;		//��������ַ����

	//���͵�����������Ϣ
	QString loaclComputerName;	//������
	QString loaclComputerIP;	//ip��ַ
	QString userAccount;		//�˺�
	QString userPassword;		//����
	int loginStatus;			//��¼״̬

	QString chatMessage_Request;	//Ҫ����������Ϣ
	QString chatMessage_Response;	//���յ���������Ϣ

	QString userName_Register;		//ע���û�������
	QString userPassword_Register;	//ע���û�������
	QString userAccount_Register;	//ע�ᵽ�û����˺�

	//���շ���������Ӧ��Ϣ
	int statusValidate;	//��¼��֤��״̬��0--��֤ʧ�ܣ�1--��֤�ɹ���2--�û��ѵ�¼

	QString thisProgramUserName;	//�˳�����û���Ψһ����

	QString userEnterMsg;	//���������ҵ���Ϣ
	QString userAccountName;//�����û�����
	QString userComputerIP;	//�����û�ip��ַ

	QString userExitName;	//�û��˳�����
	QString userExitMsg;	//�û��˳���Ϣ

private:
	QString getloaclComputerIP();	//����ip��ַ�Ļ�ȡ

public:
	void sendRequest(RequestTypeEnum);	//��������
	void sendUserLogin();		//�����¼
	void sendChatMessage();		//����������Ϣ
	void sendUserRegister();	//����ע��	

private slots:
	void dataReceived_Slot();		//���������ķ����� readyRead() �ź�
signals:
	void userLoginCheck_Signals(int);				//��¼��֤��״̬��0--��֤ʧ�ܣ�1--��֤�ɹ���2--�û��ѵ�¼
signals:
	void noticeAllClient_Signals(QString, QString);	//�����û�����ʱ����֪ͨ�����û�
signals:
	void updateAllUser_Signals(QString, QString);	//���������û�
signals:
	void userExit_Signals(QString, QString);	//�˳���Ϣ
signals:
	void chatMessage_Signals(QString);	//������Ϣ
signals:
	void userRegister_Signals(QString);	//�û�ע��


public:
	SocketConnect(QObject *parent);
	~SocketConnect();
};
