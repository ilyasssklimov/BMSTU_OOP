#include "errors.h"
#include <QMessageBox>


void show_error(const error rc)
{
    switch (rc)
    {
    case EMPTY_NAME_ERROR:
        QMessageBox::critical(NULL, "Ошибка", "Имя файла не может быть пустым");
        break;

    case FILE_ERROR:
        QMessageBox::critical(NULL, "Ошибка", "При открытии файла произошла ошибка");
        break;

    case READ_ERROR:
        QMessageBox::critical(NULL, "Ошибка", "При чтении данных из файла произошла ошибка");
        break;

    case VERTEX_SIZE_ERROR:
        QMessageBox::critical(NULL, "Ошибка", "Некорректное количество вершин (меньше двух)");
        break;

    case EDGE_SIZE_ERROR:
        QMessageBox::critical(NULL, "Ошибка", "Некорректное количество ребер (меньше одного)");
        break;

    case ALLOCATE_ERROR:
        QMessageBox::critical(NULL, "Ошибка", "При выделении файла произошла ошибка");
        break;

    case INPUT_ERROR:
        QMessageBox::critical(NULL, "Ошибка", "В полях ввода должны отсутствовать иные символы, кроме цифр, минуса и точки");
        break;

    case INIT_ERROR:
        QMessageBox::critical(NULL, "Ошибка", "Фигура еще не была создана");
        break;

    case CREATE_ERROR:
        QMessageBox::critical(NULL, "Ошибка", "Фигура уже была создана");
        break;

    case SUCCESS_SAVE:
        QMessageBox::information(NULL, "Успех", "Параметры фигуры были успешно записаны в файл");
    }
}
