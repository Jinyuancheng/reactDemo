/********************************************************************************
** Form generated from reading UI file 'test_qt_lib.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_QT_LIB_H
#define UI_TEST_QT_LIB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_test_qt_libClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *test_qt_libClass)
    {
        if (test_qt_libClass->objectName().isEmpty())
            test_qt_libClass->setObjectName(QString::fromUtf8("test_qt_libClass"));
        test_qt_libClass->resize(600, 400);
        menuBar = new QMenuBar(test_qt_libClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        test_qt_libClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(test_qt_libClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        test_qt_libClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(test_qt_libClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        test_qt_libClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(test_qt_libClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        test_qt_libClass->setStatusBar(statusBar);

        retranslateUi(test_qt_libClass);

        QMetaObject::connectSlotsByName(test_qt_libClass);
    } // setupUi

    void retranslateUi(QMainWindow *test_qt_libClass)
    {
        test_qt_libClass->setWindowTitle(QApplication::translate("test_qt_libClass", "test_qt_lib", nullptr));
    } // retranslateUi

};

namespace Ui {
    class test_qt_libClass: public Ui_test_qt_libClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_QT_LIB_H
