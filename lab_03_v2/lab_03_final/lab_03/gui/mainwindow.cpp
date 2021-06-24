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
    ui->x_shift_cam->setPlaceholderText(QString("dx"));
    ui->y_shift_cam->setPlaceholderText(QString("dy"));
    ui->z_shift_cam->setPlaceholderText(QString("dz"));
    ui->xy_angle_cam->setPlaceholderText(QString("ox"));
    ui->yz_angle_cam->setPlaceholderText(QString("oy"));
    ui->zx_angle_cam->setPlaceholderText(QString("oz"));
    ui->file_name->setPlaceholderText(QString("Имя файла"));
    ui->file_name_camera->setPlaceholderText(QString("Имя файла"));
    ui->nums_figs->setPlaceholderText(QString("Индекс модели"));
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_shift_fig_clicked()
{
    QStringList indexes = ui->nums_figs->text().split(QRegExp(" "));

    Point shift(ui->x_shift_fig->text().toDouble(), ui->y_shift_fig->text().toDouble(), ui->z_shift_fig->text().toDouble());
    Point scale(1, 1, 1);
    Point rotate(0, 0, 0);

    for(QString index: indexes)
    {
       shared_ptr<BaseCommand> command(new ReformModel(index.toInt(), shift, scale, rotate));
       _facade->execute(command);
    }

    update_scene();
}


void MainWindow::on_rotate_fig_clicked()
{
    QStringList indexes = ui->nums_figs->text().split(QRegExp(" "));

    Point shift(0, 0, 0);
    Point scale(1, 1, 1);
    Point rotate(ui->xy_angle_fig->text().toDouble(), ui->yz_angle_fig->text().toDouble(), ui->zx_angle_fig->text().toDouble());

    for(QString index: indexes)
    {
        shared_ptr<BaseCommand> command(new ReformModel(index.toInt(), shift, scale, rotate));
        _facade->execute(command);
    }
    update_scene();
}


void MainWindow::on_scale_fig_clicked()
{
    QStringList indexes = ui->nums_figs->text().split(QRegExp(" "));

    Point shift(0, 0, 0);
    Point scale(ui->x_scale_fig->text().toDouble(), ui->y_scale_fig->text().toDouble(), ui->z_scale_fig->text().toDouble());
    Point rotate(0, 0, 0);

    for(QString index: indexes)
    {
        shared_ptr<BaseCommand> command(new ReformModel(index.toInt(), shift, scale, rotate));
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
    }
    catch (BaseError &er)
    {
        print_message(er.get_info());
    }
}


void MainWindow::on_remove_fig_clicked()
{
    QStringList indexes = ui->nums_figs->text().split(QRegExp(" "));

    for(QString index: indexes)
    {
        shared_ptr<BaseCommand> command(new RemoveModel(index.toInt()));
        _facade->execute(command);
        ui->nums_figs->clear();
    }

    update_scene();
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
    ui->camera_select->addItem(QString::number(ui->camera_select->count()));
    ui->camera_select->setCurrentIndex(ui->camera_select->count() - 1);

    update_scene();
}


void MainWindow::on_shift_cam_clicked()
{
    int index = ui->camera_select->currentIndex();
    Point shift(ui->x_shift_cam->text().toDouble(), ui->y_shift_cam->text().toDouble(), ui->z_shift_cam->text().toDouble());
    Point rotate(0, 0, 0);
    shared_ptr<BaseCommand> command(new ReformCamera(index, shift, rotate));
    _facade->execute(command);

    update_scene();
}


void MainWindow::on_rotate_cam_clicked()
{
    int index = ui->camera_select->currentIndex();
    Point shift(0, 0, 0);
    Point rotate(ui->xy_angle_cam->text().toDouble(), ui->yz_angle_cam->text().toDouble(), ui->zx_angle_cam->text().toDouble());
    shared_ptr<BaseCommand> command(new ReformCamera(index, shift, rotate));
    _facade->execute(command);

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


// void MainWindow::on_MainWindow_destroyed() {}


void MainWindow::on_remove_cam_clicked()
{
    int index = ui->camera_select->currentIndex();
    shared_ptr<BaseCommand> command(new RemoveCamera(index));
    try
    {
        _facade->execute(command);
        ui->camera_select->removeItem(index);

        update_scene();
    }
    catch (BaseError &er)
    {
        print_message(er.get_info());
    }
}


void MainWindow::on_camera_select_currentIndexChanged(int index)
{
    shared_ptr<BaseCommand> command(new SetCamera(index));
    _facade->execute(command);

    update_scene();
}
