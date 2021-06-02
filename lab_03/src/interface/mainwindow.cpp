#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commands/camera/camera_command.h"
#include "commands/model/model_commands.h"
#include "exception/exception.h"
#include <QMessageBox>
#include <QFileDialog>

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::is_camera_exist()
{
    auto camera_count = make_shared<size_t>(0);

    CountCamera camera_command(camera_count);
    facade->execute(camera_command);

    if (!*camera_count)
    {
        time_t time_now = time(NULL);
        throw CameraError(__FILE__, __LINE__, ctime(&time_now));
    }
}


void MainWindow::is_camera_delete()
{
    auto model_count = std::make_shared<size_t>(0);

    CountModel model_command(model_count);
    facade->execute(model_command);

    auto camera_count = std::make_shared<size_t>(0);

    CountCamera camera_command(camera_count);
    facade->execute(camera_command);

    if (*camera_count <= 1 && *model_count)
    {
        time_t time_now = time(NULL);
        throw CameraDeleteError(__FILE__, __LINE__, ctime(&time_now));
    }
}


void MainWindow::is_model_exist() {
    auto count = std::make_shared<size_t>(0);

    CountModel model_command(count);
    facade->execute(model_command);

    if (!*count)
    {
        time_t time_now = time(NULL);
        throw ModelError(__FILE__, __LINE__, ctime(&time_now));
    }
}


void MainWindow::update_scene()
{
    DrawScene draw_command(drawer);
    facade->execute(draw_command);
}


void MainWindow::on_load_button_clicked()
{
    try
    {
       is_camera_exist();
    }
    catch (const CameraError &)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Перед тем как добавить модель, необходимо загрузить камеру");
        return;
    }


    auto tmp = QFileDialog::getOpenFileName();
    if (tmp.isNull())
        return;

    LoadModel load_command(tmp.toUtf8().data());

    try
    {
        facade->execute(load_command);
    }
    catch (const FileError &)
    {
        QMessageBox::critical(nullptr, "Ошибка", "При открытии файла произошла ошибка");
        return;
    }

    update_scene();
    ui->model_choose->addItem(QFileInfo(t.toUtf8().data()).fileName());
    ui->model_choose->setCurrentIndex(ui->model_choose->count() - 1);
}
