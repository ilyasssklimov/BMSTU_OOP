#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "Начинаем с первого этажа, жду Ваших действий";

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_floor_01_clicked()
{
    qDebug() << "Поехали на первый этаж :)";
    lift.call(1);
}

void MainWindow::on_floor_02_clicked()
{
    qDebug() << "Поехали на второй этаж :)";
    lift.call(2);
}


void MainWindow::on_floor_03_clicked()
{
    qDebug() << "Поехали на третий этаж :)";
    lift.call(3);
}


void MainWindow::on_floor_04_clicked()
{
    qDebug() << "Поехали на четвертый этаж :)";
    lift.call(4);
}


void MainWindow::on_floor_05_clicked()
{
    qDebug() << "Поехали на пятый этаж :)";
    lift.call(5);
}


void MainWindow::on_floor_06_clicked()
{
    qDebug() << "Поехали на шестой этаж :)";
    lift.call(6);
}


void MainWindow::on_floor_07_clicked()
{
    qDebug() << "Поехали на седьмой этаж :)";
    lift.call(7);
}


void MainWindow::on_floor_08_clicked()
{
    qDebug() << "Поехали на восьмой этаж :)";
    lift.call(8);
}


void MainWindow::on_floor_09_clicked()
{
    qDebug() << "Поехали на девятый этаж :)";
    lift.call(9);
}


void MainWindow::on_floor_10_clicked()
{
    qDebug() << "Поехали на десятый этаж :)";
    lift.call(10);
}
