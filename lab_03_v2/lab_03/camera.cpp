#include "camera.h"

Camera::Camera()
{
    position = Point(0, 0, 0);
    angles = Point(0, 0, 0);
}

Camera::Camera(const Point &pos, const Point &angs): position(pos), angles(angs) {};


const Point &Camera::get_position() const
{
    return position;
}


const Point &Camera::get_angles() const
{
    return angles;
}


void Camera::set_position(const Point &position)
{
    this->position = position;
}


void Camera::set_angles(const Point &angles)
{
    this->angles = angles;
}


void Camera::transform(const shared_ptr<Matrix<double>> transform_matrix)
{
    position.transform(transform_matrix);
}


void Camera::accept(shared_ptr<Visitor> visitor)
{
    visitor->visit_camera(*this);
}


void Camera::rotate(const shared_ptr<Matrix<double>> transform_matrix)
{
    angles.transform(trnsform_matrix);
}
