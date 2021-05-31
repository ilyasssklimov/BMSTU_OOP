#include "scene_manager.h"


SceneManager::SceneManager()
{
    scene = make_shared<Scene>();
}


shared_ptr<Scene> SceneManager::get_scene() const
{
    return scene;
}


shared_ptr<Camera> SceneManager::get_camera() const
{
    return camera;
}


void SceneManager::set_scene(shared_ptr<Scene> scene)
{
    this->scene = move(scene);
}


void SceneManager::set_camera(const size_t n)
{
    auto camera = scene->get_cameras().at(n);
    this->camera = camera;
}
