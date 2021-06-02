#ifndef SCENE_SOLUTION_H
#define SCENE_SOLUTION_H


#include "scene_secretary.h"


class SceneSolution
{
public:
    shared_ptr<SceneSecretary> get_scene_loader();
    shared_ptr<SceneSecretary> get_scene_loader(const shared_ptr<BaseSceneLoader> &loader);

private:
    shared_ptr<SceneSecretary> secretary;
};

#endif
