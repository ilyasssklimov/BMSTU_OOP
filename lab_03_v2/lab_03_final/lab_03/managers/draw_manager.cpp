#include "draw_manager.hpp"
#include "errors.hpp"
#include "transform_matrix.hpp"
#include <math.h>

std::shared_ptr<DrawManager> DrawManagerCreator::get_manager()
{
    if (_manager == nullptr)
        create_manager();

    return _manager;
}

void DrawManagerCreator::create_manager()
{
    static std::shared_ptr<DrawManager> _manager(new DrawManager());
    this->_manager = _manager;
}

void DrawManager::set_drawer(std::shared_ptr<BaseDrawer> _drawer)
{
    this->_drawer = _drawer;
}

void DrawManager::set_camera(std::shared_ptr<Camera> _camera)
{
    this->_camera = _camera;
}

void DrawManager::draw(std::shared_ptr<Scene> _scene)
{
    _scene->get_models()->accept(std::shared_ptr<Visitor>(new Visitor(_camera, _drawer)));
}
