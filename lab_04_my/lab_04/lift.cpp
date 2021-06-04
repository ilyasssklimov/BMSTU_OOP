#include <lift.h>


Lift::Lift() {
  QObject::connect(&controller, SIGNAL(set_aim(int, direction)), &cabin, SLOT(cabin_call(int, direction)));
  QObject::connect(&cabin, SIGNAL(cabin_crossing_floor(int, direction)), &controller, SLOT(passed_floor(int)));
  QObject::connect(&cabin, SIGNAL(cabin_stopped(int)), &controller, SLOT(achieved_floor(int)));
}


void Lift::call(int floor)
{
    controller.set_new_aim(floor);
}
