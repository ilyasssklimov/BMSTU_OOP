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

    void achived_aim();
    void new_aim();

public slots:
    void achieved_aim(int floor);
    void passed_floor(int floor);

    void busy(int floor, direction &dir);
    void free(int floor);

private:
    enum state { FREE, BUSY };
    state cur_state;

    int cur_floor;
    int cur_aim;

    QVector<bool> is_aim;
    direction cur_direction;

    bool nearest_floor(int &floor);
    void find_new_aim();
};
