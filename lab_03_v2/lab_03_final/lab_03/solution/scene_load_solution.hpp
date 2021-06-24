#ifndef SCENE_LOAD_SOLUTION_H
#define SCENE_LOAD_SOLUTION_H

#define SCENE_CFG_PATH "./data/scene_load.cfg"

#include "solution_manager.hpp"


class SceneLoadSolution
{
public:
    SceneLoadSolution() = default;

    std::shared_ptr<SceneLoaderCreator> get_creator();
};


#endif
