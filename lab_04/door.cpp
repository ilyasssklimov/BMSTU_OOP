#include <door.h>

#include <QDebug>

Door::Door(QObject *parent) : QObject(parent), cur_state(CLOSED)
{
  doors_stay_open_timer.setInterval(WAITING_TIME);
  doors_stay_open_timer.setSingleShot(true);

  doors_open_timer.setSingleShot(true);
  doors_close_timer.setSingleShot(true);

  QObject::connect(&doors_open_timer, SIGNAL(timeout()), this, SLOT(open()));
  QObject::connect(&doors_close_timer, SIGNAL(timeout()), this, SLOT(close()));
  QObject::connect(this, SIGNAL(opened_doors()), &doors_stay_open_timer, SLOT(start()));
  QObject::connect(&doors_stay_open_timer, SIGNAL(timeout()), this, SLOT(start_closing()));
}


void Door::start_openning()
{
    if (cur_state == CLOSED)
    {
        cur_state = OPENNING;
        qDebug() << "Двери открываются";
        doors_open_timer.start(DOORS_TIME);
    }
    else if (cur_state == CLOSING)
    {
        cur_state = OPENNING;
        qDebug() << "Двери открываются";
        int t = doors_close_timer.remainingTime();
        doors_close_timer.stop();
        doors_open_timer.start(DOORS_TIME - t);
    }
}


void Door::start_closing()
{
    /*
    if (cur_state == CLOSED)
        closed_doors();
    else
    */
    if (cur_state == OPENED)
    {
        cur_state = CLOSING;
        qDebug() << "Осторожно, двери закрываются";
        doors_close_timer.start(DOORS_TIME);
    }
}


void Door::open()
{
    if (cur_state == OPENNING)
    {
        cur_state = OPENED;
        qDebug() << "Двери открылись, ожидаю пассажиров";
        opened_doors();
    }
}


void Door::close() {
    if (cur_state == CLOSING)
    {
        cur_state = CLOSED;
        qDebug() << "Двери закрылись :(";
        closed_doors();
    }
}
