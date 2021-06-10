#ifndef CABIN_H
#define CABIN_H

#include <QObject>
#include <QTimer>
#include <door.h>
#include "consts.h"


class Cabin: public QObject
{
    Q_OBJECT

public:
    explicit Cabin(QObject *parent = nullptr);

signals:
    void cabin_called();
    void cabin_stopped();
    void cabin_crossed_floor(int, const direction &_direction);
    void cabin_stay_closed(int floor);

public slots:
    void move();
    void stay_not_closed();
    void stay_closed();
    void start_moving(int floor, const direction &dir);

private:
    enum cabin_state { STAY_CLOSED, START_MOVING, MOVE, STAY_NOT_CLOSED };
    int cur_floor = 1;
    direction cur_direction = STAY;
    Door _doors;
    cabin_state _state = STAY_CLOSED;
    QTimer cross_floor_timer;
};

#endif
