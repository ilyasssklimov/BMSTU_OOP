#ifndef CAMERA_H
#define CAMERA_H


#include "../base_object.h"
#include "./visitor/visitor.h"

using namespace std;


class Camera: public BaseObject
{
public:
    Camera() = default;
    explicit Camera(const Vertex &position);

    void transform(const Vertex &move, const Vertex &scale, const Vertex &turn) override;
    void accept(shared_ptr<Visitor> visitor) override;

    Vertex get_position();

    void move_x(const double dx);
    void move_y(const double dy);
    void move_z(const double dz);

    ~Camera() override = default;

private:
    Vertex position;

};

#endif
