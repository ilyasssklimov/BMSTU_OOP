#ifndef BASE_VISITOR_HPP
#define BASE_VISITOR_HPP


using namespace std;


class Model;
class Camera;
class Composite;


class BaseVisitor
{
public:
    BaseVisitor() = default;
    virtual ~BaseVisitor() = default;

    virtual void visit_model(Model &_model) = 0;
    virtual void visit_camera(Camera &) = 0;
    virtual void visit_composite(Composite &) = 0;
};


#endif
