#include "draw_manager.h"


void DrawManager::visit(const Model &model)
{
    auto verteces = model.get_elements()->get_verteces();
    auto edges = model.get_elements()->get_edges();
    auto center = model.get_elements()->get_center();

    for (auto edge: edges)
        drawer->create_line(projection(verteces.at(edge.get_start()) + center),
                            projection(verteces.at(edge.get_finish()) + center));

}


void DrawManager::visit(const Camera &) {};
void DrawManager::visit(const Composite &) {};


void DrawManager::set_drawer(shared_ptr<BaseDraw> drawer)
{
    this->drawer = drawer;
}


void DrawManager::set_camera(shared_ptr<Camera> camera)
{
    this->camera = camera;
}


Vertex DrawManager::projection(const Vertex &point)
{
    Vertex projection_point(point);
    Vertex camera_position(camera->get_position());

    projection_point.set_x(projection_point.get_x() + camera_position.get_x());
    projection_point.set_y(projection_point.get_y() + camera_position.get_y());

    return projection_point;
}
