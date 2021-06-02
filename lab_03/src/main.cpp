#include "./interface/mainwindow.h"
#include "config/config_creator.h"
#include "config/config_reader.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    auto config = ConfigCreator().get_config();

    if (config->get_frame() == ConfigReader::QT)
    {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    }

    return 0;
}
