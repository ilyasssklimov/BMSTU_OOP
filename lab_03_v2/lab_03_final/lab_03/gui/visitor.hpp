#ifndef VISITOR_HPP
#define VISITOR_HPP

#include "drawer.hpp"
#include "base_visitor.hpp"

using namespace std;


class Visitor: public BaseVisitor
{
public:
    Visitor() = default;
    Visitor(const shared_ptr<Camera> &_camera, const shared_ptr<BaseDrawer> _drawer);
    ~Visitor() = default;

    virtual void visit_model(Model &_model) override;
    virtual void visit_camera(Camera &) override;
    virtual void visit_composite(Composite &) override;

private:
    Point get_projection(Point &_point);
    shared_ptr<Camera> _camera;
    shared_ptr<BaseDrawer> _drawer;
};


#endif
