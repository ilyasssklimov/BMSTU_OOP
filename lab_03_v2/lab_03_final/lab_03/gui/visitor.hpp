#ifndef VISITOR_HPP
#define VISITOR_HPP

#include "drawer.hpp"

class Model;
class Camera;
class Composite;

class Visitor
{
public:
    Visitor() = default;
    Visitor(const std::shared_ptr<Camera> &_camera, const std::shared_ptr<BaseDrawer> _drawer);
    ~Visitor() =default;

    void visit_model(Model &_model);
    void visit_camera(Camera &) {};
    void visit_composite(Composite &) {};

private:
    Point get_projection(Point &_point);
    std::shared_ptr<Camera> _camera;
    std::shared_ptr<BaseDrawer> _drawer;
};

#endif
