#include "drawer.h"

void QtDrawer::draw_line(const Point &p1, const Point &p2)
{
    canvas->draw_line(p1, p2);
}

void QtDrawer::set_canvas(shared_ptr<base_canvas> canvas)
{
    this->canvas = canvas;
}

void QtDrawer::clear_scene()
{
    canvas->clear();
}
