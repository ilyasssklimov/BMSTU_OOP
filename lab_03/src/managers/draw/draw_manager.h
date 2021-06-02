#ifndef DRAW_MANAGER_H
#define DRAW_MANAGER_H


#include <memory>
#include "../base_manager.h"
#include "./visitor/visitor.h"
#include "./draw/base_draw.h"

using namespace std;


class DrawManager: public BaseManager, public Visitor
{
public:
    DrawManager() = default;

    void visit(const Model &model) override;
    void visit(const Camera &camera) override;
    void visit(const Composite &composite) override;

    void set_drawer(shared_ptr<BaseDraw> drawer);
    void set_camera(shared_ptr<Camera> camera);

    ~DrawManager() = default;

private:
    shared_ptr<BaseDraw> drawer;
    shared_ptr<Camera> camera;
    Vertex projection(const Vertex &point);
};

#endif
