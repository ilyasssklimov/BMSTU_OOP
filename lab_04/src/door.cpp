#include <QDebug>
#include "door.h"


Door::Door(QObject *parent) : QObject(parent)
{
    doors_stay_timer.setInterval(STAY_TIME);

    doors_stay_timer.setSingleShot(true);
    doors_open_timer.setSingleShot(true);
    doors_close_timer.setSingleShot(true);

    QObject::connect(&doors_open_timer, SIGNAL(timeout()), this, SLOT(opened()));
    QObject::connect(&doors_close_timer, SIGNAL(timeout()), this, SLOT(closed()));
    QObject::connect(&doors_stay_timer, SIGNAL(timeout()), this, SLOT(closing()));
    QObject::connect(this, SIGNAL(doors_opened()), &doors_stay_timer, SLOT(start()));
}


void Door::opening()
{
    if (_state != CLOSING && _state != CLOSED)
        return;

    qDebug() << "Двери открываются";
    if (_state == CLOSED)
    {
        _state = OPENING;
        doors_open_timer.start(DOORS_TIME);
    }
    else
    {
        _state = OPENING;
        int t = doors_close_timer.remainingTime();
        doors_close_timer.stop();
        doors_open_timer.start(DOORS_TIME - t);
    }
}


void Door::closing()
{
    if (_state != OPENED)
        return;

    _state = CLOSING;

    qDebug() << "Осторожно, двери закрываются";

    doors_close_timer.start(DOORS_TIME);
}


void Door::opened()
{
    if (_state != OPENING)
        return;

    _state = OPENED;
    qDebug() << "Двери открылись";

    emit doors_opened();
}


void Door::closed()
{
    if (_state != CLOSING)
        return;

    _state = CLOSED;
    qDebug() << "Двери закрылись :(";

    emit doors_closed();
}
