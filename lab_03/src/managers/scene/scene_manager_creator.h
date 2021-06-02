#ifndef SCENE_MANAGER_CREATOR_H
#define SCENE_MANAGER_CREATOR_H


#include <memory>
#include "scene_manager.h"

using namespace std;


class SceneManagerCreator
{
public:
    shared_ptr<SceneManager> get_manager();

private:
    shared_ptr<SceneManager> manager;
};

#endif
