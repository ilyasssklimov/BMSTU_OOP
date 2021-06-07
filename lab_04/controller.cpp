#include <controller.h>
#include <QDebug>


Controller::Controller(QObject *parent): QObject(parent), cur_state(FREE), cur_floor(1),
    cur_aim(-1), is_aim(FLOORS, false), cur_direction(STAY) {}


void Controller::set_new_aim(int floor)
{
    cur_state = BUSY;
    is_aim[floor - 1] = true;

    if ((cur_aim == -1) || (cur_direction == UP && floor > cur_aim) || (cur_direction == DOWN && floor < cur_aim))
        cur_aim = floor;

    nearest_floor(floor);
    if (cur_floor > cur_aim)
        cur_direction = DOWN;
    else
        cur_direction = UP;

    emit set_aim(floor, cur_direction);
}


void Controller::achieved_aim(int floor)
{
    if (cur_state == BUSY)
    {
        cur_floor = floor;
        is_aim[floor - 1] = false;

        if (cur_floor == cur_aim)
        {
            cur_aim = -1;
            find_new_aim();
        }

        if (nearest_floor(floor))
        {
            if (cur_floor > cur_aim)
                cur_direction = DOWN;
            else
                cur_direction = UP;

            emit set_aim(floor, cur_direction);
        }
        else
            cur_state = FREE;
    }
}


void Controller::passed_floor(int floor)
{
    cur_floor = floor;
    qDebug() << "Проехали мимо" << floor << "этажа";
}


void Controller::find_new_aim()
{
    int state = false;

    if (cur_direction == UP)
    {
        for (int i = FLOORS; i >= 1 && !state; i--)
            if (is_aim[i - 1])
            {
                state = true;
                cur_aim = i;
            }
    }
    else
    {
        for (int i = 1; i <= FLOORS && !state; i++)
            if (is_aim[i - 1])
            {
                state = true;
                cur_aim = i;
            }
    }
}


bool Controller::nearest_floor(int &floor)
{
    bool state = false;
    if (cur_aim > cur_floor)
    {
        for (int i = cur_floor; i <= FLOORS && !state; i += 1)
            if (is_aim[i - 1])
            {
                floor = i;
                state = true;
            }
    }
    else
    {
        for (int i = cur_floor; i >= 1 && !state; i -= 1)
        {
            if (is_aim[i - 1])
            {
                floor = i;
                state = true;
            }
        }
    }
    return state;
}
