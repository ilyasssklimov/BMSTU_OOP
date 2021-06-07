#include "builder.h"
#include "errors.h"

bool model_builder::is_build()
{
    return _elements != nullptr;
}

void model_builder::build()
{
    _elements.reset();
    _elements = make_shared<Elements>();
}

void model_builder::build_verteces(vector<Point> pts)
{
    if (!is_build())
    {
        string message = "Error while building point";
        throw file_error(message);
    }
    for (auto _point : pts)
        _elements->add_point(_point);
}

void model_builder::build_edges(vector<Edge> eds)
{
    if (!is_build())
    {
        string message = "Error while building edge";
        throw file_error(message);
    }
    for (auto _edge : eds)
        _elements->add_edge(_edge);
}

shared_ptr<object> model_builder::get()
{
    return shared_ptr<model>(new model(_elements));
}

void scene_builder::build()
{
    _scene = shared_ptr<scene>(new scene);
}

bool scene_builder::is_build()
{
    return _scene != nullptr;
}

shared_ptr<scene> scene_builder::get()
{
    return shared_ptr<scene>(_scene);
}

void scene_builder::build_model(const shared_ptr<object> &_model)
{
    _scene->add_model(_model);
}

void scene_builder::build_camera(const shared_ptr<object> &_camera)
{
    _scene->add_camera(_camera);
}

void camera_builder::build()
{
    position.set_x(0);
    position.set_y(0);
    position.set_z(0);
    angles.set_x(0);
    angles.set_y(0);
    angles.set_z(0);
}

bool camera_builder::is_build()
{
    return true;
}

shared_ptr<object> camera_builder::get()
{
    //return std::dynamic_pointer_cast<object>(_camera);
    return shared_ptr<camera>(new camera(position, angles));
}

void camera_builder::build_pos(double x, double y, double z)
{
    position.set_x(x);
    position.set_y(y);
    position.set_z(z);
}

void camera_builder::build_angles(double ox, double oy, double oz)
{
    angles.set_x(ox);
    angles.set_y(oy);
    angles.set_z(oz);
}
