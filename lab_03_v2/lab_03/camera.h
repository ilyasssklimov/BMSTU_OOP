#ifndef OBJECT_CAMERA_H
#define OBJECT_CAMERA_H

#include "base_object.h"
#include "visitor.h"
#include "commands.h"

class Camera : public InvisibleObject
{
    friend class Visitor;
    friend class TransformCamera;
public:
    Camera();
    explicit Camera(const Point &pos, const Point &angs);
/*
    const point &get_position() const;
    const point &get_angles() const;
    void set_position(const point &position);
    void set_angles(const point &angles);
    void rotate(const std::shared_ptr<Matrix<double>> reform_mtr);
*/
    void transform(const shared_ptr<Matrix<double>> reform_mtr) override;
    bool is_composite() override { return false; }
    void accept(shared_ptr<Visitor> _visitor) override;

private:
    Point position;
    Point angles;

    const Point &get_position() const;
    const Point &get_angles() const;
    void set_position(const Point &position);
    void set_angles(const Point &angles);
    void rotate(const shared_ptr<Matrix<double>> reform_mtr);
};

#endif
