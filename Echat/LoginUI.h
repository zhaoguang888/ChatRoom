#pragma once

#include <QDialog>
#include "ui_LoginUI.h"
#include "socketConnect.h"
#include "RegisterUI.h"

class LoginUI : public QDialog
{
	Q_OBJECT
public:
	LoginUI(QWidget *parent = Q_NULLPTR);
	~LoginUI();

private:
	RegisterUI* r;

private slots:
	void btnConnectServer_Slots();	//���ӷ�������ť
	void btnLogin_Slots();			//��¼��ť
	void btnRegister_Slots();		//ע�ᰴť

	void dataCheck_Slots(int);	//�������գ���¼�����Ϣ

//��������
private:
	QPixmap titleIMG;//��¼����ͼƬ
	bool isDragging; // �Ƿ������϶�
	QPoint startPosition; // �϶���ʼǰ�����λ��
	QPoint widgetPosition; // �����ԭʼλ��
private:
	virtual void mouseMoveEvent(QMouseEvent * event);
	virtual void mousePressEvent(QMouseEvent * event);
	virtual void mouseReleaseEvent(QMouseEvent * event);

	virtual void paintEvent(QPaintEvent *event);
private:
	inline QString readFile(QString); //����styleSheet�ļ�
	void initTitle();	//��ʼ������
private slots:
	void on_minBtn_clicked();	//��С����ť
	void on_closeBtn_clicked();	//�رհ�ť

private:
	virtual void closeEvent(QCloseEvent *event);
private:
	Ui::LoginUI ui;
};
