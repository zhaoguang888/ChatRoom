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
	void btnConnectServer_Slots();	//连接服务器按钮
	void btnLogin_Slots();			//登录按钮
	void btnRegister_Slots();		//注册按钮

	void dataCheck_Slots(int);	//第三接收：登录检查信息

//美化部分
private:
	QPixmap titleIMG;//登录背景图片
	bool isDragging; // 是否正在拖动
	QPoint startPosition; // 拖动开始前的鼠标位置
	QPoint widgetPosition; // 窗体的原始位置
private:
	virtual void mouseMoveEvent(QMouseEvent * event);
	virtual void mousePressEvent(QMouseEvent * event);
	virtual void mouseReleaseEvent(QMouseEvent * event);

	virtual void paintEvent(QPaintEvent *event);
private:
	inline QString readFile(QString); //加载styleSheet文件
	void initTitle();	//初始化标题
private slots:
	void on_minBtn_clicked();	//最小化按钮
	void on_closeBtn_clicked();	//关闭按钮

private:
	virtual void closeEvent(QCloseEvent *event);
private:
	Ui::LoginUI ui;
};
