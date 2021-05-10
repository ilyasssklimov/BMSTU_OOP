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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QPushButton *createButton;
    QLineEdit *createEdit;
    QPushButton *saveButton;
    QLineEdit *saveEdit;
    QLabel *carryoverLabel;
    QLabel *dxLabel;
    QLineEdit *dxEdit;
    QLabel *dyLabel;
    QLineEdit *dyEdit;
    QLabel *dzLabel;
    QLineEdit *dzEdit;
    QPushButton *carryoverButton;
    QLabel *scaleLabel;
    QLabel *kxLabel;
    QLineEdit *kxEdit;
    QLabel *kyLabel;
    QLineEdit *kyEdit;
    QLabel *kzLabel;
    QLineEdit *kzEdit;
    QPushButton *scaleButton;
    QLabel *turnLabel;
    QLabel *oxLabel;
    QLineEdit *oxEdit;
    QLabel *oyLabel;
    QLineEdit *oyEdit;
    QLabel *ozLabel;
    QLineEdit *ozEdit;
    QPushButton *turnButton;
    QSpacerItem *verticalSpacer;
    QGraphicsView *graphicsView;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1266, 730);
        MainWindow->setMinimumSize(QSize(1266, 730));
        MainWindow->setMaximumSize(QSize(1266, 730));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(970, 10, 271, 691));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        createButton = new QPushButton(formLayoutWidget);
        createButton->setObjectName(QString::fromUtf8("createButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(createButton->sizePolicy().hasHeightForWidth());
        createButton->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        createButton->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, createButton);

        createEdit = new QLineEdit(formLayoutWidget);
        createEdit->setObjectName(QString::fromUtf8("createEdit"));
        createEdit->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, createEdit);

        saveButton = new QPushButton(formLayoutWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, saveButton);

        saveEdit = new QLineEdit(formLayoutWidget);
        saveEdit->setObjectName(QString::fromUtf8("saveEdit"));
        saveEdit->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, saveEdit);

        carryoverLabel = new QLabel(formLayoutWidget);
        carryoverLabel->setObjectName(QString::fromUtf8("carryoverLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(12);
        carryoverLabel->setFont(font1);
        carryoverLabel->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(3, QFormLayout::SpanningRole, carryoverLabel);

        dxLabel = new QLabel(formLayoutWidget);
        dxLabel->setObjectName(QString::fromUtf8("dxLabel"));
        dxLabel->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, dxLabel);

        dxEdit = new QLineEdit(formLayoutWidget);
        dxEdit->setObjectName(QString::fromUtf8("dxEdit"));
        dxEdit->setFont(font);

        formLayout->setWidget(4, QFormLayout::FieldRole, dxEdit);

        dyLabel = new QLabel(formLayoutWidget);
        dyLabel->setObjectName(QString::fromUtf8("dyLabel"));
        dyLabel->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, dyLabel);

        dyEdit = new QLineEdit(formLayoutWidget);
        dyEdit->setObjectName(QString::fromUtf8("dyEdit"));
        dyEdit->setFont(font);

        formLayout->setWidget(5, QFormLayout::FieldRole, dyEdit);

        dzLabel = new QLabel(formLayoutWidget);
        dzLabel->setObjectName(QString::fromUtf8("dzLabel"));
        dzLabel->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, dzLabel);

        dzEdit = new QLineEdit(formLayoutWidget);
        dzEdit->setObjectName(QString::fromUtf8("dzEdit"));
        dzEdit->setFont(font);

        formLayout->setWidget(6, QFormLayout::FieldRole, dzEdit);

        carryoverButton = new QPushButton(formLayoutWidget);
        carryoverButton->setObjectName(QString::fromUtf8("carryoverButton"));
        carryoverButton->setFont(font);

        formLayout->setWidget(7, QFormLayout::SpanningRole, carryoverButton);

        scaleLabel = new QLabel(formLayoutWidget);
        scaleLabel->setObjectName(QString::fromUtf8("scaleLabel"));
        scaleLabel->setFont(font1);
        scaleLabel->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(8, QFormLayout::SpanningRole, scaleLabel);

        kxLabel = new QLabel(formLayoutWidget);
        kxLabel->setObjectName(QString::fromUtf8("kxLabel"));
        kxLabel->setFont(font);

        formLayout->setWidget(9, QFormLayout::LabelRole, kxLabel);

        kxEdit = new QLineEdit(formLayoutWidget);
        kxEdit->setObjectName(QString::fromUtf8("kxEdit"));
        kxEdit->setFont(font);

        formLayout->setWidget(9, QFormLayout::FieldRole, kxEdit);

        kyLabel = new QLabel(formLayoutWidget);
        kyLabel->setObjectName(QString::fromUtf8("kyLabel"));
        kyLabel->setFont(font);

        formLayout->setWidget(10, QFormLayout::LabelRole, kyLabel);

        kyEdit = new QLineEdit(formLayoutWidget);
        kyEdit->setObjectName(QString::fromUtf8("kyEdit"));
        kyEdit->setFont(font);

        formLayout->setWidget(10, QFormLayout::FieldRole, kyEdit);

        kzLabel = new QLabel(formLayoutWidget);
        kzLabel->setObjectName(QString::fromUtf8("kzLabel"));
        kzLabel->setFont(font);

        formLayout->setWidget(11, QFormLayout::LabelRole, kzLabel);

        kzEdit = new QLineEdit(formLayoutWidget);
        kzEdit->setObjectName(QString::fromUtf8("kzEdit"));
        kzEdit->setFont(font);

        formLayout->setWidget(11, QFormLayout::FieldRole, kzEdit);

        scaleButton = new QPushButton(formLayoutWidget);
        scaleButton->setObjectName(QString::fromUtf8("scaleButton"));
        scaleButton->setFont(font);

        formLayout->setWidget(12, QFormLayout::SpanningRole, scaleButton);

        turnLabel = new QLabel(formLayoutWidget);
        turnLabel->setObjectName(QString::fromUtf8("turnLabel"));
        turnLabel->setFont(font1);
        turnLabel->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(13, QFormLayout::SpanningRole, turnLabel);

        oxLabel = new QLabel(formLayoutWidget);
        oxLabel->setObjectName(QString::fromUtf8("oxLabel"));
        oxLabel->setFont(font);

        formLayout->setWidget(14, QFormLayout::LabelRole, oxLabel);

        oxEdit = new QLineEdit(formLayoutWidget);
        oxEdit->setObjectName(QString::fromUtf8("oxEdit"));
        oxEdit->setFont(font);

        formLayout->setWidget(14, QFormLayout::FieldRole, oxEdit);

        oyLabel = new QLabel(formLayoutWidget);
        oyLabel->setObjectName(QString::fromUtf8("oyLabel"));
        oyLabel->setFont(font);

        formLayout->setWidget(15, QFormLayout::LabelRole, oyLabel);

        oyEdit = new QLineEdit(formLayoutWidget);
        oyEdit->setObjectName(QString::fromUtf8("oyEdit"));
        oyEdit->setFont(font);

        formLayout->setWidget(15, QFormLayout::FieldRole, oyEdit);

        ozLabel = new QLabel(formLayoutWidget);
        ozLabel->setObjectName(QString::fromUtf8("ozLabel"));
        ozLabel->setFont(font);

        formLayout->setWidget(16, QFormLayout::LabelRole, ozLabel);

        ozEdit = new QLineEdit(formLayoutWidget);
        ozEdit->setObjectName(QString::fromUtf8("ozEdit"));
        ozEdit->setFont(font);

        formLayout->setWidget(16, QFormLayout::FieldRole, ozEdit);

        turnButton = new QPushButton(formLayoutWidget);
        turnButton->setObjectName(QString::fromUtf8("turnButton"));
        turnButton->setFont(font);

        formLayout->setWidget(17, QFormLayout::SpanningRole, turnButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::SpanningRole, verticalSpacer);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(30, 10, 911, 691));
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        createButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        carryoverLabel->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\264\320\262\320\270\320\263 \320\276\320\261\321\212\320\265\320\272\321\202\320\260\n"
" \320\277\320\276 \320\272\320\260\320\266\320\264\320\276\320\271 \320\270\320\267 \320\276\321\201\320\265\320\271", nullptr));
        dxLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 \320\276\321\201\320\270 X", nullptr));
        dxEdit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        dyLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 \320\276\321\201\320\270 Y", nullptr));
        dyEdit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        dzLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 \320\276\321\201\320\270 Z", nullptr));
        dzEdit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        carryoverButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \321\201\320\264\320\262\320\270\320\263", nullptr));
        scaleLabel->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\321\213\n"
"\320\274\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        kxLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 \320\276\321\201\320\270 X", nullptr));
        kxEdit->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        kyLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 \320\276\321\201\320\270 Y", nullptr));
        kyEdit->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        kzLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 \320\276\321\201\320\270 Z", nullptr));
        kzEdit->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        scaleButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\274\320\260\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        turnLabel->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\203\320\263\320\276\320\273 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260\n"
"\320\276\321\202\320\275\320\276\321\201\320\270\321\202\320\265\320\273\321\214\320\275\320\276 \320\276\321\201\320\265\320\271", nullptr));
        oxLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 \320\276\321\201\320\270 X", nullptr));
        oxEdit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        oyLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 \320\276\321\201\320\270 Y", nullptr));
        oyEdit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        ozLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 \320\276\321\201\320\270 Z", nullptr));
        ozEdit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        turnButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \320\277\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
