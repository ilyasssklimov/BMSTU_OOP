#include "canvas.hpp"

void QtCanvas::create_line(const Point &p1, const Point &p2)
{
    scene->addLine(p1.get_x(), p1.get_y(), p2.get_x(), p2.get_y());
}

void QtCanvas::clear()
{
    scene->clear();
}
