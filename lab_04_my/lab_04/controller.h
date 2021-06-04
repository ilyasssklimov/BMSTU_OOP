#pragma once

#include <QObject>
#include <QVector>

#include <consts.h>

class Controller : public QObject {
    Q_OBJECT

public:
    explicit Controller(QObject *parent = nullptr);
    void set_new_aim(int floor);

signals:
    void set_aim(int floor, direction dir);

public slots:
    void achieved_floor(int floor);
    void passed_floor(int floor);

private:
    enum state { FREE, BUSY };
    int cur_floor;
    int cur_aim;

    QVector<bool> is_aim;
    state cur_state;
    direction cur_direction;
    bool nearest_floor(int &floor);
    void find_new_target();
};
