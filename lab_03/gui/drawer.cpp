#include "drawer.hpp"

void QtDrawer::create_line(const Point &p1, const Point &p2)
{
    canvas->create_line(p1, p2);
}

void QtDrawer::set_canvas(std::shared_ptr<BaseCanvas> canvas)
{
    this->canvas = canvas;
}

void QtDrawer::clear_scene()
{
    canvas->clear();
}
