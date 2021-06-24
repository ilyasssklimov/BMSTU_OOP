#ifndef DRAWER_HPP
#define DRAWER_HPP

#include <QGraphicsScene>
#include "point.hpp"
#include "canvas.hpp"


class BaseDrawer
{
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = default;

    virtual void set_canvas(std::shared_ptr<BaseCanvas> canvas) = 0;
    virtual void create_line(const Point &point1, const Point &point2) = 0;
    virtual void clear_scene() = 0;

protected:
    std::shared_ptr<BaseCanvas> canvas;
};

class QtDrawer: public BaseDrawer
{
public:
    QtDrawer() = default;

    void set_canvas(std::shared_ptr<BaseCanvas> canvas) override;
    void create_line(const Point &point1, const Point &point2) override;
    void clear_scene() override;
};


#endif
