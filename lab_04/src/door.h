#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QTimer>
#include "consts.h"


class Door : public QObject
{
    Q_OBJECT

public:
    explicit Door(QObject *parent = nullptr);

signals:
    void doors_closed();
    void doors_opened();

public slots:
    void opening();
    void closing();

private slots:
    void opened();
    void closed();

private:
    enum doors_state { CLOSED, OPENING, OPENED, CLOSING };

    doors_state _state = CLOSED;
    QTimer doors_open_timer;
    QTimer doors_stay_timer;
    QTimer doors_close_timer;
};

#endif
