#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H


#include <iostream>
#include <memory>
#include "../base_manager.h"
#include "./scene/scene.h"

using namespace std;


class SceneManager: public BaseManager
{
public:
    SceneManager();

    shared_ptr<Scene> get_scene() const;
    shared_ptr<Camera> get_camera() const;

    void set_scene(shared_ptr<Scene> scene);
    void set_camera(const size_t n);

private:
    shared_ptr<Scene> scene;
    shared_ptr<Camera> camera;
};


#endif
