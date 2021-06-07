#include <cabin.h>
#include <QDebug>


Cabin::Cabin(QObject *parent):
    QObject(parent), state(STOP), cur_floor(1), cur_aim(-1), new_aim(false), cur_direction(STAY)
{
  crossing_floor_timer.setSingleShot(true);

  QObject::connect(this, SIGNAL(cabin_called()), &doors, SLOT(start_closing()));
  QObject::connect(this, SIGNAL(cabin_reached_aim(int)), this, SLOT(cabin_stopping()));
  QObject::connect(this, SIGNAL(cabin_stopped(int)), &doors, SLOT(start_openning()));
  QObject::connect(&doors, SIGNAL(closed_doors()), this, SLOT(cabin_move()));
  QObject::connect(&crossing_floor_timer, SIGNAL(timeout()), this, SLOT(cabin_move()));
}


void Cabin::cabin_move()
{
    if (new_aim && state == WAIT)
    {
        state = MOVE;
        if (cur_floor == cur_aim)
            emit cabin_reached_aim(cur_floor);
        else
            crossing_floor_timer.start(CROSSING_FLOOR);
    }
    else if (state == MOVE)
    {
        cur_floor += cur_direction;

        if (cur_floor == cur_aim)
            emit cabin_reached_aim(cur_floor);
        else
        {
            emit cabin_crossing_floor(cur_floor, cur_direction);
            crossing_floor_timer.start(CROSSING_FLOOR);
        }
    }
}


void Cabin::cabin_stopping()
{
    if (state == MOVE)
    {
        state = STOP;
        qDebug() << "Приехали на" << cur_floor << "этаж";
        emit cabin_stopped(cur_floor);
    }
}


void Cabin::cabin_call(int floor, direction direction)
{
    if (state == STOP)
    {
        cur_aim = floor;
        new_aim = true;
        state = WAIT;
        cur_direction = direction;
        emit cabin_called();
    }
}
