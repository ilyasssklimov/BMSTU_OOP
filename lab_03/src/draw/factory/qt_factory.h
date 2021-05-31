#ifndef QT_FACTORY_H
#define QT_FACTORY_H


#include "abstract_factory.h"
#include <QGraphicsScene>


class QtFactory: public AbstractFactory
{
public:
    explicit QtFactory(QGraphicsScene *scene);
    unique_ptr<BaseDraw> create_scene() override;

private:
    QGraphicsScene *scene;
};


#endif
