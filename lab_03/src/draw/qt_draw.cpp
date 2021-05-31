#include "qt_draw.h"


QtDraw::QtDraw(QGraphicsScene *scene): scene(scene) {};


QtDraw::QtDraw(const QtDraw &drawer): scene(drawer.scene) {};


void QtDraw::create_line(const Vertex &start, const Vertex &finish)
{
    scene->addLine(start.get_x(), start.get_y(), finish.get_x(), finish.get_y());
}


void QtDraw::clear_scene()
{
    scene->clear();
}
