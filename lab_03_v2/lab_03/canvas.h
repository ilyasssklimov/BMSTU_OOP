#ifndef CANVAS_H
#define CANVAS_H

#include "QGraphicsScene"
#include "point.h"

class base_canvas
{
public:
    virtual void draw_line(const Point &p1, const Point &p2) = 0;
    virtual void clear() = 0;
};

class QtCanvas : public base_canvas
{
public:
    //explicit qt_canvas(std::shared_ptr<QGraphicsScene> canvas) : scene(canvas) {}
    explicit QtCanvas(QGraphicsScene *canvas) : scene(canvas) {}
    void draw_line(const Point &p1, const Point &p2) override;
    void clear() override;

private:
    //std::shared_ptr<QGraphicsScene> scene;
    QGraphicsScene *scene;
};

#endif // CANVAS_H
