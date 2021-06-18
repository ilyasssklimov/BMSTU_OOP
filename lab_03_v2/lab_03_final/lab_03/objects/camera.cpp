#include "camera.hpp"

Camera::Camera()
{
    position = Point(0, 0, 0);
    angles = Point(0, 0, 0);
}

Camera::Camera(const Point &pos, const Point &angs)
    :position(pos), angles(angs)
{
}

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

void Camera::reform(const std::shared_ptr<Matrix<double>> reform_mtr)
{
    position.reform(reform_mtr);
}

void Camera::accept(std::shared_ptr<Visitor> _visitor)
{
    _visitor->visit_camera(*this);
}

void Camera::rotate(const std::shared_ptr<Matrix<double>> reform_mtr)
{
    angles.reform(reform_mtr);
}
