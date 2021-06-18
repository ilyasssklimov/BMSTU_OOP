#ifndef OBJECT_CAMERA_HPP
#define OBJECT_CAMERA_HPP

#include "object.hpp"
#include "visitor.hpp"
#include "commands.hpp"

class Camera : public InvisibleObject
{
    friend class Visitor;
    friend class ReformCamera;
public:
    Camera();
    explicit Camera(const Point &pos, const Point &angs);
    void reform(const std::shared_ptr<Matrix<double>> reform_mtr) override;
    bool is_composite() override { return false; }
    void accept(std::shared_ptr<Visitor> _visitor) override;

private:
    Point position;
    Point angles;

    const Point &get_position() const;
    const Point &get_angles() const;
    void set_position(const Point &position);
    void set_angles(const Point &angles);
    void rotate(const std::shared_ptr<Matrix<double>> reform_mtr);
};

#endif
