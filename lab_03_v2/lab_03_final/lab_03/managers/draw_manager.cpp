#include "draw_manager.hpp"
#include "errors.hpp"
#include "transform_matrix.hpp"
#include <math.h>


using namespace std;


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


void DrawManager::set_drawer(shared_ptr<BaseDrawer> _drawer)
{
    this->_drawer = _drawer;
}


void DrawManager::set_camera(shared_ptr<Camera> _camera)
{
    this->_camera = _camera;
}


void DrawManager::draw(shared_ptr<Scene> _scene)
{
    _scene->get_models()->accept(shared_ptr<Visitor>(new Visitor(_drawer)));
}
