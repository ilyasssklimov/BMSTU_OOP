#include "draw_manager.h"
#include "errors.h"
#include "transform_matrix.h"
#include <math.h>


shared_ptr<DrawManager> DrawManagerCreator::get_manager()
{
    if (_manager == nullptr)
        create_manager();

    return _manager;
}

void DrawManagerCreator::create_manager()
{
    static shared_ptr<DrawManager> _manager(new DrawManager());
    this->_manager = _manager;
}

void DrawManager::set_drawer(shared_ptr<BaseDrawer> drawer)
{
    this->drawer = drawer;
}

void DrawManager::set_camera(shared_ptr<Camera> camera)
{
    this->camera = camera;
}

void DrawManager::draw(shared_ptr<Scene> _scene)
{
    scene->get_models()->accept(shared_ptr<Visitor>(new Visitor(camera, drawer)));
}
