#ifndef VISITOR_HPP
#define VISITOR_HPP

#include "drawer.hpp"

class Model];
class Camera;
class Composite;

class Visitor
{
public:
    Visitor() = default;
    Visitor(const shared_ptr<camera> &camera, const shared_ptr<BaseDrawer> drawer);
    ~Visitor() =default;

    void visit_model(Model &model);
    void visit_camera(Camera &camera) {};
    void visit_composite(Composite &composite) {};

private:
    Point get_projection(Point &point);
    shared_ptr<Camera> camera;
    shared_ptr<BaseDrawer> drawer;
};

#endif
