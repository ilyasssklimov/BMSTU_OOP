#ifndef DRAW_MANAGER_h
#define DRAW_MANAGER_h

#include <memory>
#include "visitor.h"
#include "scene.h"
#include "base_manager.h"

class DrawManager : public BaseManager
{
public:
    DrawManager() = default;
    ~DrawManager() = default;

    void set_drawer(shared_ptr<BaseDrawer> _drawer);
    void set_camera(shared_ptr<Camera> _camera);

    void draw(shared_ptr<Scene> _scene);

private:
    shared_ptr<Visitor> _visitor;
    shared_ptr<BaseDrawer> _drawer;
    shared_ptr<Camera> _camera;
};

class DrawManagerCreator
{
public:
    shared_ptr<DrawManager> get_manager();

private:
    void create_manager();

    shared_ptr<DrawManager> _manager;
};

#endif // DRAW_MANAGER_h
