#include "scene_manager.h"

shared_ptr<SceneManager> SceneManagerCreator::get_manager()
{
    if (_manager == nullptr)
        create_manager();

    return _manager;
}

void SceneManagerCreator::create_manager()
{
    static shared_ptr<SceneManager> _manager(new SceneManager());
    this->_manager = _manager;
}

SceneManager::SceneManager(): scene(new Scene), camera(nullptr) {};


shared_ptr<Scene> SceneManager::get_scene()
{
    return scene;
}

shared_ptr<Camera> SceneManager::get_camera()
{
    return camera;
}

void SceneManager::set_camera(long index)
{
    if (_scene->get_cameras()->get_objects().size() < 1)
    {
        camera = nullptr;
        return;
    }
    shared_ptr<BaseObject> cam = _scene->get_cameras()->get_objects().at(index);
    camera = dynamic_pointer_cast<Camera>(cam);
}
