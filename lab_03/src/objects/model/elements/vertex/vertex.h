#ifndef VERTEX_H
#define VERTEX_H


class Vertex
{
public:
    Vertex() = default;
    Vertex(const double x, const double y, const double z);

    double get_x() const;
    double get_y() const;
    double get_z() const;

    void set_x(const double x);
    void set_y(const double y);
    void set_z(const double z);

    void turn_x(const double ox);
    void turn_y(const double oy);
    void turn_z(const double oz);

    void move(const double dx, const double dy, const double dz);
    void scale(const double kx, const double ky, const double kz);
    void turn(const double ox, const double oy, const double oz);

    Vertex operator + (const Vertex &vertex);
    Vertex operator - (const Vertex &vertex);

    ~Vertex() = default;

private:
    double x, y, z;
};

#endif
