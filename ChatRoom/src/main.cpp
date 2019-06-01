#include <QtWidgets/QApplication>
#include "ChatRoomUI.h"
#include "LoginUI.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	LoginUI l;
	ChatRoomUI w;
	int ok = l.exec();

	if (ok == QDialog::Accepted)
	{
		w.show();
		return a.exec();
	}
	else
	{
		return 0;
	}
}
