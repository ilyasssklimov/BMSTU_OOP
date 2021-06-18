#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <QGraphicsScene>
#include "point.hpp"


class BaseCanvas
{
public:
    virtual void create_line(const Point &p1, const Point &p2) = 0;
    virtual void clear() = 0;
};


class QtCanvas : public BaseCanvas
{
public:
    explicit QtCanvas(QGraphicsScene *canvas) : scene(canvas) {}
    void create_line(const Point &p1, const Point &p2) override;
    void clear() override;

private:
    QGraphicsScene *scene;
};


#endif
