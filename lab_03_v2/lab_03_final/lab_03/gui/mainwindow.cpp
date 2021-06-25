#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPainter>
#include <QVector3D>
#include <QMessageBox>
#include <QStringList>
#include <QDebug>
#include <QRegExp>
#include <chrono>
#include <ctime>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "drawer_solution.hpp"
#include "scene_manager.hpp"
#include <string>
using namespace std;


QGraphicsScene *Scene;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), _facade(new Facade)
{
    ui->setupUi(this);
    setup_scene();

    ui->x_shift_fig->setPlaceholderText(QString("dx"));
    ui->y_shift_fig->setPlaceholderText(QString("dy"));
    ui->z_shift_fig->setPlaceholderText(QString("dz"));
    ui->x_scale_fig->setPlaceholderText(QString("kx"));
    ui->y_scale_fig->setPlaceholderText(QString("ky"));
    ui->z_scale_fig->setPlaceholderText(QString("kz"));
    ui->xy_angle_fig->setPlaceholderText(QString("ox"));
    ui->yz_angle_fig->setPlaceholderText(QString("oy"));
    ui->zx_angle_fig->setPlaceholderText(QString("oz"));
    ui->file_name->setPlaceholderText(QString("Имя файла"));
    ui->file_name_camera->setPlaceholderText(QString("Имя файла"));
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_shift_fig_clicked()
{
    QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();
    if (selectedRows.size() <= 0)
    {
        QMessageBox::information(this, "Error", "Выберите хотя бы один объект из списка");
        return;
    }

    Point shift(ui->x_shift_fig->text().toDouble(), ui->y_shift_fig->text().toDouble(), ui->z_shift_fig->text().toDouble());
    Point scale(1, 1, 1);
    Point rotate(0, 0, 0);

    for(int i = 0; i < selectedRows.size(); i++)
    {
        string name = ui->tableWidget->item(selectedRows[0].row(), 0)->text().toStdString();
        string id = name.substr(name.find("№") + 1);

        shared_ptr<BaseCommand> command(new ReformObject(atoi(id.c_str()), shift, scale, rotate));
        _facade->execute(command);
    }

    update_scene();
}


void MainWindow::on_rotate_fig_clicked()
{
    QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();
    if (selectedRows.size() <= 0)
    {
        QMessageBox::information(this, "Error", "Выберите хотя бы один объект из списка");
        return;
    }

    Point shift(0, 0, 0);
    Point scale(1, 1, 1);
    Point rotate(ui->xy_angle_fig->text().toDouble(), ui->yz_angle_fig->text().toDouble(), ui->zx_angle_fig->text().toDouble());

    for(int i = 0; i < selectedRows.size(); i++)
    {
        string name = ui->tableWidget->item(selectedRows[0].row(), 0)->text().toStdString();
        string id = name.substr(name.find("№") + 1);

        shared_ptr<BaseCommand> command(new ReformObject(atoi(id.c_str()), shift, scale, rotate));
        _facade->execute(command);
    }

    update_scene();
}


void MainWindow::on_scale_fig_clicked()
{
    QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();
    if (selectedRows.size() <= 0)
    {
        QMessageBox::information(this, "Error", "Выберите хотя бы один объект из списка");
        return;
    }

    Point shift(0, 0, 0);
    Point scale(ui->x_scale_fig->text().toDouble(), ui->y_scale_fig->text().toDouble(), ui->z_scale_fig->text().toDouble());
    Point rotate(0, 0, 0);

    for(int i = 0; i < selectedRows.size(); i++)
    {
        string name = ui->tableWidget->item(selectedRows[0].row(), 0)->text().toStdString();
        string id = name.substr(name.find("№") + 1);

        shared_ptr<BaseCommand> command(new ReformObject(atoi(id.c_str()), shift, scale, rotate));
        _facade->execute(command);
    }


    update_scene();
}


void MainWindow::on_import_fig_clicked()
{
    shared_ptr<BaseCommand> command(new LoadModel(ui->file_name->text().toStdString()));
    try
    {
        _facade->execute(command);
        update_scene();

        ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
        int number = SceneManagerCreator().get_manager()->get_scene()->get_last_id();
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem(QStringLiteral("Модель №%1").arg(number)));

    }
    catch (BaseError &er)
    {
        print_message(er.get_info());
    }
}


void MainWindow::print_message(string str)
{
    QMessageBox msg;
    msg.setText(QString().fromUtf8(str.c_str()));
    msg.exec();
}


void MainWindow::on_add_cam_clicked()
{
    shared_ptr<BaseCommand> command(new LoadCamera(ui->file_name_camera->text().toStdString()));
    _facade->execute(command);

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    int number = SceneManagerCreator().get_manager()->get_scene()->get_last_id();
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem(QStringLiteral("Камера №%1").arg(number)));

    ui->tableWidget->selectRow(ui->tableWidget->rowCount() - 1);
    on_set_cam_clicked();
    update_scene();
}


void MainWindow::setup_scene()
{
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    try
    {
        shared_ptr<AbstractFactory> factory = DrawerSolution().get_factory();
        drawer = shared_ptr<BaseDrawer>(factory->create_ui());
        drawer->set_canvas(make_shared<QtCanvas>(scene));
    }
    catch (BaseError &er)
    {
        print_message(er.get_info());
    }
}


void MainWindow::update_scene()
{
    shared_ptr<BaseCommand> command(new DrawScene(drawer));
    _facade->execute(command);
}


void MainWindow::on_remove_obj_clicked()
{
    QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();
    if (selectedRows.size() <= 0)
    {
        QMessageBox::information(this, "Error", "Выберите хотя бы один объект из списка");
        return;
    }

    for (int i = 0; i < selectedRows.size(); i++)
    {
        while (!selectedRows.empty())
        {
            string name = ui->tableWidget->item(selectedRows[0].row(), 0)->text().toStdString();
            string id = name.substr(name.find("№") + 1);

            shared_ptr<BaseCommand> command(new RemoveObject(atoi(id.c_str())));
            _facade->execute(command);

            ui->tableWidget->removeRow(selectedRows[0].row());
            selectedRows = ui->tableWidget->selectionModel()->selectedRows();
        }
    }
    update_scene();
}


void MainWindow::on_set_cam_clicked()
{
    QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();
    if (selectedRows.size() <= 0)
    {
        QMessageBox::information(this, "Error", "Выберите хотя бы один объект из списка");
        return;
    }

    int id = ui->tableWidget->item(selectedRows[0].row(), 0)->text().toInt();

    shared_ptr<BaseCommand> command(new SetCamera(id));
    _facade->execute(command);

    update_scene();
}
