#include "builder.hpp"
#include "errors.hpp"


bool ModelBuilder::is_build()
{
    return _details != nullptr;
}


void ModelBuilder::build()
{
    _details.reset();
    _details = std::make_shared<Details>();
}


void ModelBuilder::build_points(std::vector<Point> pts)
{
    if (!is_build())
    {
        std::string message = "Ошибка во время построения вершин";
        throw FileError(message);
    }
    for (auto _point : pts)
        _details->add_point(_point);
}


void ModelBuilder::build_edges(std::vector<Edge> eds)
{
    if (!is_build())
    {
        std::string message = "Ошибка во время построения рёбер";
        throw FileError(message);
    }
    for (auto _edge : eds)
        _details->add_edge(_edge);
}


std::shared_ptr<Object> ModelBuilder::get()
{
    return std::shared_ptr<Model>(new Model(_details));
}


void SceneBuilder::build()
{
    _scene = std::shared_ptr<Scene>(new Scene);
}


bool SceneBuilder::is_build()
{
    return _scene != nullptr;
}


std::shared_ptr<Scene> SceneBuilder::get()
{
    return std::shared_ptr<Scene>(_scene);
}


void SceneBuilder::build_model(const std::shared_ptr<Object> &_model)
{
    _scene->add_model(_model);
}


void SceneBuilder::build_camera(const std::shared_ptr<Object> &_camera)
{
    _scene->add_camera(_camera);
}


void CameraBuilder::build()
{
    position.set_x(0);
    position.set_y(0);
    position.set_z(0);
    angles.set_x(0);
    angles.set_y(0);
    angles.set_z(0);
}


bool CameraBuilder::is_build()
{
    return true;
}


std::shared_ptr<Object> CameraBuilder::get()
{
    return std::shared_ptr<Camera>(new Camera(position, angles));
}


void CameraBuilder::build_pos(double x, double y, double z)
{
    position.set_x(x);
    position.set_y(y);
    position.set_z(z);
}


void CameraBuilder::build_angles(double ox, double oy, double oz)
{
    angles.set_x(ox);
    angles.set_y(oy);
    angles.set_z(oz);
}
