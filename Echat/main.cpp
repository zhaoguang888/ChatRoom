#include <QtWidgets/QApplication>
#include "ClientUI.h"
#include "LoginUI.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	LoginUI d;
	ClientUI w;
	int ok = d.exec();

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
