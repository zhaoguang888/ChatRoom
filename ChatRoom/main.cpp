#include "ChatRoomUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ChatRoomUI w;
	w.show();
	return a.exec();
}
