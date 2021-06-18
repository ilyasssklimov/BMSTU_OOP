#include "scene_manager.hpp"

std::shared_ptr<scene_manager> scene_manager_creator::get_manager()
{
    if (_manager == nullptr)
        create_manager();

    return _manager;
}

void scene_manager_creator::create_manager()
{
    static std::shared_ptr<scene_manager> _manager(new scene_manager());
    this->_manager = _manager;
}

scene_manager::scene_manager()
    :_scene(new Scene), _camera(nullptr)
{
}

std::shared_ptr<Scene> scene_manager::get_scene()
{
    return _scene;
}

std::shared_ptr<Camera> scene_manager::get_camera()
{
    return _camera;
}

void scene_manager::set_camera(int index)
{
    if (_scene->get_cameras()->get_objects().size() < 1)
    {
        _camera = nullptr;
        return;
    }
    std::shared_ptr<Object> cam = _scene->get_cameras()->get_objects().at(index);
    _camera = std::dynamic_pointer_cast<Camera>(cam);
}
