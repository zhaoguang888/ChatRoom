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

	//���շ���������Ӧ��Ϣ
	QString thisProgramUserName;	//����һ��������û�����

	QString userEnterMsg;	//���������ҵ���Ϣ
	QString userAccountName;//�����û�����
	QString userComputerIP;	//�����û�ip��ַ

	QString userExitName;	//�û��˳�����
	QString userExitMsg;	//�û��˳���Ϣ



private:
	QString getloaclComputerIP();	//����ip��ַ��ȡ����

//����
public:
	void sendRequest(RequestType);	//��������
	void sendUserLogin();			//�����¼

private slots:
	void dataReceived_Slot();		//���������ķ����� readyRead() �ź�

signals:
	void userLoginCheck_Signals(int);		//��¼��֤��״̬��0--��֤ʧ�ܣ�1--��֤�ɹ���2--�û��ѵ�¼
signals:
	void noticeAllClient_Signals(QString, QString);	//�����û�����ʱ����֪ͨ�����û�
signals:
	void updateAllUser_Signals(QString, QString);	//���������û�
signals:
	void userExit_Signals(QString, QString);	//���������û�


public:
	SocketConnect(QObject *parent);
	~SocketConnect();
};
