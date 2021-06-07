#ifndef DRAWER_SOLUTION_H
#define DRAWER_SOLUTION_H

#define SCENE_CFG_PATH "./data/drawer.cfg"

#include "solution_manager.h"

class drawer_solution
{
public:
    drawer_solution() = default;

    shared_ptr<AbstractFactory> get_factory();
};

#endif // DRAWER_SOLUTION_H
