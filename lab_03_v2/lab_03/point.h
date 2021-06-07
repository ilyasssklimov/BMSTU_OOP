#ifndef POINT_H
#define POINT_H

#include <memory>
#include "matrix.hpp"

class Point
{
public:
    Point();
    Point(const double x, const double y, const double z);
    ~Point() = default;

    double get_x() const { return x; };
    void set_x(double x) { this->x = x; };

    double get_y() const { return y; };
    void set_y(double y) { this->y = y; };

    double get_z() const { return z; };
    void set_z(double z) { this->z = z; };

    void transform(const shared_ptr<Matrix<double>> mtr);
    Point deg_to_rad() const;

private:
    double x;
    double y;
    double z;
};

#endif // POINT_H
