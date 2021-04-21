#include <QGraphicsScene>
#include <QPen>


void QtDrawLine(QGraphicsScene &widget, const double x1, const double y1, const double x2, const double y2)
{
    QPen pen(Qt::black, 2, Qt::SolidLine);
    widget.addLine(x1, y1, x2, y2, pen);
}


void QtClear(QGraphicsScene &widget)
{
    widget.clear();
}
