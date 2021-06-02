#ifndef VISITOR_H
#define VISITOR_H

// #include "./objects/model/model.h"
// #include "./objects/camera/camera.h"
// #include "./objects/composite/composite.h"


class Camera;
class Composite;
class Model;


class Visitor
{
public:
    Visitor() = default;

    virtual void visit(const Model &model) = 0;
    virtual void visit(const Camera &camera) = 0;
    virtual void visit(const Composite &composite) = 0;

    ~Visitor() = default;
};

#endif
