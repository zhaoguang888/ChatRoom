#pragma once

#include <QtWidgets/QWidget>
#include "ui_ChatRoomUI.h"

class ChatRoomUI : public QWidget
{
	Q_OBJECT

public:
	ChatRoomUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::ChatRoomUIClass ui;
};
