#ifndef QT_DRAW_H
#define QT_DRAW_H


#include <QGraphicsScene>
#include "base_draw.h"


class QtDraw: public BaseDraw
{
public:
    QtDraw() = delete;
    explicit QtDraw(QGraphicsScene *scene);
    QtDraw(const QtDraw &drawer);

    void create_line(const Vertex &start, const Vertex &finish) override;
    void clear_scene() override;

private:
    QGraphicsScene *scene;
};

#endif
