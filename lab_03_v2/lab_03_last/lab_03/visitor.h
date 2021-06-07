#ifndef VISITOR_H
#define VISITOR_H

#include "drawer.h"

class Model;
class Camera;
class Composite;


using namespace std;


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
