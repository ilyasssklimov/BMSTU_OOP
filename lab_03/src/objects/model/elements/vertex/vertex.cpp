#include "vertex.h"
#include <math.h>


inline void get_sin_cos(double &sin_angle, double &cos_angle, double angle)
{
    double radians_angle = angle * M_PI / 180;
    sin_angle = sin(radians_angle);
    cos_angle = cos(radians_angle);
}


Vertex::Vertex(const double x, const double y, const double z): x(x), y(y), z(z) {};


double Vertex::get_x() const
{
    return x;
}


double Vertex::get_y() const
{
    return y;
}


double Vertex::get_z() const
{
    return z;
}


void Vertex::set_x(const double x)
{
    this->x = x;
}


void Vertex::set_y(const double y)
{
    this->y = y;
}


void Vertex::set_z(const double z)
{
    this->z = z;
}


void Vertex::move(const double dx, const double dy, const double dz)
{
    set_x(x + dx);
    set_y(y + dy);
    set_z(z + dz);
}


void Vertex::scale(const double kx, const double ky, const double kz)
{
    set_x(x * kx);
    set_y(y * ky);
    set_z(z * kz);
}


void Vertex::turn(const double ox, const double oy, const double oz)
{
    turn_x(ox);
    turn_y(oy);
    turn_z(oz);
}


void Vertex::turn_x(const double ox)
{
    double tmp_y = y,
           tmp_z = z;
    double sin_angle, cos_angle;
    get_sin_cos(sin_angle, cos_angle, ox);

    y = tmp_y * cos_angle - tmp_z * sin_angle;
    z = tmp_y * sin_angle + tmp_z * cos_angle;

}


void Vertex::turn_y(const double oy)
{
    double tmp_x = x,
           tmp_z = z;
    double sin_angle, cos_angle;
    get_sin_cos(sin_angle, cos_angle, oy);

    x = tmp_x * cos_angle + tmp_z * sin_angle;
    z = -tmp_x * sin_angle + tmp_z * cos_angle;
}


void Vertex::turn_z(const double oz)
{
    double tmp_x = x,
           tmp_y = y;
    double sin_angle, cos_angle;
    get_sin_cos(sin_angle, cos_angle, oz);

    x = tmp_x * cos_angle - tmp_y * sin_angle;
    y = tmp_x * sin_angle + tmp_y * cos_angle;
}


Vertex Vertex::operator + (const Vertex &vertex)
{
    Vertex new_vertex(*this);

    new_vertex.set_x(new_vertex.get_x() + vertex.get_x());
    new_vertex.set_y(new_vertex.get_y() + vertex.get_y());
    new_vertex.set_z(new_vertex.get_z() + vertex.get_z());

    return new_vertex;
}


Vertex Vertex::operator - (const Vertex &vertex)
{
    Vertex new_vertex(*this);

    new_vertex.set_x(new_vertex.get_x() - vertex.get_x());
    new_vertex.set_y(new_vertex.get_y() - vertex.get_y());
    new_vertex.set_z(new_vertex.get_z() - vertex.get_z());

    return new_vertex;
}


