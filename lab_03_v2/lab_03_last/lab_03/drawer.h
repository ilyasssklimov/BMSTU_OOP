#ifndef DRAWER_H
#define DRAWER_H

#include <QGraphicsScene>
#include "point.h"

#include "canvas.h"


using namespace std;


class BaseDrawer
{
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = default;

    virtual void set_canvas(shared_ptr<base_canvas> canvas) = 0;
    virtual void draw_line(const Point &point1, const Point &point2) = 0;
    virtual void clear_scene() = 0;

protected:
    shared_ptr<base_canvas> canvas;
};

class QtDrawer : public BaseDrawer
{
public:
    QtDrawer() = default;

    void set_canvas(shared_ptr<base_canvas> canvas) override;
    void draw_line(const Point &point1, const Point &point2) override;
    void clear_scene() override;
};

#endif // DRAWER_H
