#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test_qt_lib.h"

class test_qt_lib : public QMainWindow
{
	Q_OBJECT

public:
	test_qt_lib(QWidget *parent = Q_NULLPTR);

private:
	Ui::test_qt_libClass ui;
};
