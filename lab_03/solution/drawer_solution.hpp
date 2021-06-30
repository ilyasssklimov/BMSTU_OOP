#ifndef DRAWER_SOLUTION_HPP
#define DRAWER_SOLUTION_HPP

#define SCENE_CFG_PATH "./data/drawer.cfg"

#include "solution_manager.hpp"


class DrawerSolution
{
public:
    DrawerSolution() = default;

    std::shared_ptr<AbstractFactory> get_factory();
};

#endif
