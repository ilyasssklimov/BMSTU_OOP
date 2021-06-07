#ifndef SCENE_LOAD_SOLUTION_H
#define SCENE_LOAD_SOLUTION_H

#define SCENE_CFG_PATH "./data/scene_load.cfg"

#include "solution_manager.h"


using namespace std;


class SceneLoadSolution
{
public:
    SceneLoadSolution() = default;

    shared_ptr<SceneLoaderCreator> get_creator();
};

#endif
