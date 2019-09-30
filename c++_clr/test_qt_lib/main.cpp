#include "test_qt_lib.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	test_qt_lib w;
	w.show();
	return a.exec();
}
