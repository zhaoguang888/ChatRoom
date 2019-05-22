#pragma once

#include <QTcpSocket>
#include <QHostAddress>

enum MessageType
{
	//�û���¼   ������Ϣ   �û��˳�     ��¼��֤         ֪ͨ���пͻ���   ֪֮ͨǰ��¼���û������Լ�����Ϣ   ע����Ϣ
	UserLogin, Information, UserExit, receiveServerCheck, noticeAnyClient, updateBeforeUserInformation, RegisterInformation
};

class socketConnect : public QTcpSocket
{
	Q_OBJECT

public:
	int port;	//�˿ںţ��ڲ�����
	QString ip;	//��¼����ķ�����ip��ַ

	//Ҫ���͵ĵ�¼��Ϣ
	QString loaclAccount;	//�����˺�
	QString loaclPassword;	//��������

	QString noticeEnter;	//һ���û���������Ϣ
	QString userClientName;	//�û�������
	QString ipAddress;	//IP��ַ

	QString updateBefore_Name;	//���û��������������
	QString uodateBefore_ip;	//���û����������ip��ַ

	QString nameID;	//���ͻ����Լ����е�����
	QString ipID;	//���ͻ����Լ����е�ip��ַ

	int check;	//��¼��֤��״̬��0--��֤ʧ�ܣ�1--��֤�ɹ���2--�û��ѵ�¼

	QString chatMessage_Receive;	//�ӷ�������������������Ϣ

	//ע�Ṧ��
	QString name_Register;		//ע������
	QString password_Register;	//ע������
	QString account_Register;	//���������ص��˺�

private:
	QHostAddress *serverIP;

	//Ҫ���͵ĵ�¼��Ϣ
	QString loaclHostName;	//������
	QString getLocalIP();		//����ip��ַ��ȡ����
	QString localIP;		//����ip��ַ
	int loginStatus;		//������¼״̬

public:
	QString chatMessage_Send;	//Ҫ����������Ϣ
	QString exitMessage;	//�˳���Ϣ
	QString exitName;		//�˳���Ϣ������
	QString registerAccount;	//ע���û����������������˺�

	bool ToConnectHost();	//���ӷ���������
	void sendMessage(MessageType);	//������Ϣ
	void sendLoginInfo();	//���͵�¼��Ϣ
	void sendChatMessage();	//����������Ϣ
	void sendOneselfInformation();	//�����û���ʱ�������Լ�����Ϣ
	//ע����Ϣ
	void sendRegisterInformation();

private slots:
	void connectSuccess_Slot();	//���ӳɹ��󷢳� connected() �ź�
	void dataReceived_Slot();	//���������ķ����� readyRead() �ź�
	void disConnected_Slot();	//�Ͽ����Ӻ󷢴�� disconnected() �ź�

signals:
	void receiveChatMessage(QString);	//����������Ϣ
signals:
	void receiveCheck(int);		//������֤��Ϣ����¼�ɹ����ѵ�¼���˺Ż��������
signals:
	void enterNotice(QString,QString,QString);					//��һ���գ�����������֪ͨ
signals:
	void updateBeforeUserInformation_Signals(QString, QString);	//�ڶ����գ������û��������ʱ��֪ͨ������
signals:
	void exitInformation_Signal(QString,QString);	//�˳���Ϣ
signals:
	void registerInformation_Signals(QString);	//ע�Ṧ��


//����ģʽ
private:
	socketConnect(QObject *parent);
	~socketConnect();
public:
	static socketConnect* GetIntance();
private:
	static socketConnect* instance;
};
