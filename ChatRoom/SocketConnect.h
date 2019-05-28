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
	int statusValidate;	//��¼��֤��״̬��0--��֤ʧ�ܣ�1--��֤�ɹ���2--�û��ѵ�¼

	//���͵�����������Ϣ
	QString loaclComputerName;	//������
	QString loaclComputerIP;	//ip��ַ
	QString UserAccount;		//�˺�
	QString UserPassword;		//����
	int loginStatus;			//��¼״̬

	QString chatMessage_Request;	//Ҫ����������Ϣ
	QString chatMessage_Response;

	//���շ���������Ӧ��Ϣ
	QString thisProgramUserName;	//�˳�����û���Ψһ����

	QString userEnterMsg;	//���������ҵ���Ϣ
	QString userAccountName;//�����û�����
	QString userComputerIP;	//�����û�ip��ַ

	QString userExitName;	//�û��˳�����
	QString userExitMsg;	//�û��˳���Ϣ

	//ע����Ϣ
	QString name_Register;		//ע������
	QString password_Register;	//ע������
	QString account_Register;	//���������ص��˺�


private:
	QString getloaclComputerIP();	//����ip��ַ��ȡ����

//����
public:
	void sendRequest(RequestTypeEnum);	//��������

	void sendUserLogin();			//�����¼
	void sendChatMessage();			//����������Ϣ
	void sendRegisterMessage();		//ע����Ϣ

private slots:
	void dataReceived_Slot();		//���������ķ����� readyRead() �ź�

signals:
	void userLoginCheck_Signals(int);		//��¼��֤��״̬��0--��֤ʧ�ܣ�1--��֤�ɹ���2--�û��ѵ�¼
signals:
	void noticeAllClient_Signals(QString, QString);	//�����û�����ʱ����֪ͨ�����û�
signals:
	void updateAllUser_Signals(QString, QString);	//���������û�
signals:
	void userExit_Signals(QString, QString);	//�˳���Ϣ
signals:
	void ChatMessage_Signals(QString);	//������Ϣ
signals:
	void userRegister_Signals(QString);	//ע����Ϣ


public:
	SocketConnect(QObject *parent);
	~SocketConnect();
};
