/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *floor_10;
    QPushButton *floor_09;
    QPushButton *floor_08;
    QPushButton *floor_07;
    QPushButton *floor_06;
    QPushButton *floor_05;
    QPushButton *floor_04;
    QPushButton *floor_03;
    QPushButton *floor_02;
    QPushButton *floor_01;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(315, 588);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 301, 541));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        floor_10 = new QPushButton(verticalLayoutWidget);
        floor_10->setObjectName(QString::fromUtf8("floor_10"));
        QFont font;
        font.setPointSize(10);
        floor_10->setFont(font);

        verticalLayout->addWidget(floor_10);

        floor_09 = new QPushButton(verticalLayoutWidget);
        floor_09->setObjectName(QString::fromUtf8("floor_09"));
        floor_09->setFont(font);

        verticalLayout->addWidget(floor_09);

        floor_08 = new QPushButton(verticalLayoutWidget);
        floor_08->setObjectName(QString::fromUtf8("floor_08"));
        floor_08->setFont(font);

        verticalLayout->addWidget(floor_08);

        floor_07 = new QPushButton(verticalLayoutWidget);
        floor_07->setObjectName(QString::fromUtf8("floor_07"));
        floor_07->setFont(font);

        verticalLayout->addWidget(floor_07);

        floor_06 = new QPushButton(verticalLayoutWidget);
        floor_06->setObjectName(QString::fromUtf8("floor_06"));
        floor_06->setFont(font);

        verticalLayout->addWidget(floor_06);

        floor_05 = new QPushButton(verticalLayoutWidget);
        floor_05->setObjectName(QString::fromUtf8("floor_05"));
        floor_05->setFont(font);

        verticalLayout->addWidget(floor_05);

        floor_04 = new QPushButton(verticalLayoutWidget);
        floor_04->setObjectName(QString::fromUtf8("floor_04"));
        floor_04->setFont(font);

        verticalLayout->addWidget(floor_04);

        floor_03 = new QPushButton(verticalLayoutWidget);
        floor_03->setObjectName(QString::fromUtf8("floor_03"));
        floor_03->setFont(font);

        verticalLayout->addWidget(floor_03);

        floor_02 = new QPushButton(verticalLayoutWidget);
        floor_02->setObjectName(QString::fromUtf8("floor_02"));
        floor_02->setFont(font);

        verticalLayout->addWidget(floor_02);

        floor_01 = new QPushButton(verticalLayoutWidget);
        floor_01->setObjectName(QString::fromUtf8("floor_01"));
        floor_01->setFont(font);

        verticalLayout->addWidget(floor_01);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 315, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        floor_10->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        floor_09->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        floor_08->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        floor_07->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        floor_06->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        floor_05->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        floor_04->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        floor_03->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        floor_02->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        floor_01->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
