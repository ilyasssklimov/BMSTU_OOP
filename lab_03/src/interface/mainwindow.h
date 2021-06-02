#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "facade/facade.h"
#include "draw/base_draw.h"
#include <memory>

using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void is_camera_exist();
    void is_camera_delete();
    void is_model_exist();
    void update_scene();


private slots:
    void on_load_button_clicked();

private:
    Ui::MainWindow *ui;
    shared_ptr<Facade> facade;
    shared_ptr<BaseDraw> drawer;
};
#endif
