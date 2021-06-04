#include <QObject>


#include "controller.h"
#include "cabin.h"


class Lift: public QObject
{
    Q_OBJECT;

public:
    Lift();
    void call(int floor);

private:
    Controller controller;
    Cabin cabin;
};
