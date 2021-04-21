#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "figure.h"
#include "action.h"
#include <string.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Преобразование объекта");

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}


MainWindow::~MainWindow()
{
    data_to_draw data;
    do_action(data, QUIT);

    delete ui;
}


void MainWindow::on_createButton_clicked()
{
    data_to_draw data;
    data.scene.graph_window = ui->graphicsView->scene();

    QString filename = ui->createEdit->text();
    data.filename = strdup(filename.toStdString().c_str());
    ui->createEdit->clear();

    error rc = do_action(data, CREATE);
    if (rc)
        show_error(rc);
    else
    {
        rc = do_action(data, DRAW);
        if (!rc)
            show_error(rc);
    }


    free(data.filename);
}


void MainWindow::on_carryoverButton_clicked()
{
    data_to_draw data;
    data.scene.graph_window = ui->graphicsView->scene();
    triplet &coeffs = data.coefficients;

    bool isXDouble = false;
    bool isYDouble = false;
    bool isZDouble = false;
    coeffs.x = ui->dxEdit->text().toDouble(&isXDouble);
    coeffs.y = ui->dyEdit->text().toDouble(&isYDouble);
    coeffs.z = ui->dzEdit->text().toDouble(&isZDouble);

    if (isXDouble && isYDouble && isZDouble)
    {
        error rc = do_action(data, CARRYOVER);
        if (rc)
            show_error(rc);
        else
        {
            rc = do_action(data, DRAW);
            if (rc)
                show_error(rc);
        }
    }
    else
        show_error(INPUT_ERROR);
}


void MainWindow::on_scaleButton_clicked()
{
    data_to_draw data;
    data.scene.graph_window = ui->graphicsView->scene();
    triplet &coeffs = data.coefficients;

    bool isXDouble = false;
    bool isYDouble = false;
    bool isZDouble = false;
    coeffs.x = ui->kxEdit->text().toDouble(&isXDouble);
    coeffs.y = ui->kyEdit->text().toDouble(&isYDouble);
    coeffs.z = ui->kzEdit->text().toDouble(&isZDouble);

    if (isXDouble && isYDouble && isZDouble)
    {
        error rc = do_action(data, SCALE);
        if (rc)
            show_error(rc);
        else
        {
            rc = do_action(data, DRAW);
            if (rc)
                show_error(rc);
        }
    }
    else
        show_error(INPUT_ERROR);
}


void MainWindow::on_turnButton_clicked()
{
    data_to_draw data;
    data.scene.graph_window = ui->graphicsView->scene();
    triplet &coeffs = data.coefficients;

    bool isXDouble = false;
    bool isYDouble = false;
    bool isZDouble = false;
    coeffs.x = ui->oxEdit->text().toDouble(&isXDouble);
    coeffs.y = ui->oyEdit->text().toDouble(&isYDouble);
    coeffs.z = ui->ozEdit->text().toDouble(&isZDouble);

    if (isXDouble && isYDouble && isZDouble)
    {
        error rc = do_action(data, TURN);
        if (rc)
            show_error(rc);
        else
        {
            rc = do_action(data, DRAW);
            if (rc)
                show_error(rc);
        }
    }
    else
        show_error(INPUT_ERROR);
}

void MainWindow::on_saveButton_clicked()
{
    data_to_draw data;

    QString filename = ui->saveEdit->text();
    data.filename = strdup(filename.toStdString().c_str());
    ui->saveEdit->clear();

    do_action(data, SAVE);

    free(data.filename);
}

