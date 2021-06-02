#include "camera.h"


Camera::Camera(const Vertex &position): position(position) {};


void Camera::accept(shared_ptr<Visitor> visitor)
{
    visitor->visit(*this);
}


void Camera::transform(const Vertex &move, const Vertex &, const Vertex &)
{
    move_x(move.get_x());
    move_y(move.get_y());
    move_z(move.get_z());
}


Vertex Camera::get_position()
{
    return position;
}


void Camera::move_x(const double dx)
{
    position.set_x(position.get_x() + dx);
}


void Camera::move_y(const double dy)
{
    position.set_y(position.get_y() + dy);
}


void Camera::move_z(const double dz)
{
    position.set_z(position.get_x() + dz);
}
