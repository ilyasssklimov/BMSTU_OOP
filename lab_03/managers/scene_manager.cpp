#include "scene_manager.hpp"


using namespace std;


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


SceneManager::SceneManager(): _scene(new Scene), _camera(nullptr) {}


shared_ptr<Scene> SceneManager::get_scene()
{
    return _scene;
}


shared_ptr<Camera> SceneManager::get_camera()
{
    return _camera;
}


void SceneManager::set_camera(int id)
{
    shared_ptr<Object> cam = _scene->get_object(id);
    _camera = dynamic_pointer_cast<Camera>(cam);
}


bool SceneManager::is_camera_exist()
{
    return _camera != nullptr;
}
