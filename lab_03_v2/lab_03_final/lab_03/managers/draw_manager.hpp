#ifndef DRAW_MANAGER_HPP
#define DRAW_MANAGER_HPP

#include <memory>
#include "visitor.hpp"
#include "scene.hpp"
#include "base_manager.hpp"


using namespace std;


class DrawManager : public BaseManager
{
public:
    DrawManager() = default;
    ~DrawManager() = default;

    void set_drawer(shared_ptr<BaseDrawer> _drawer);
    void set_camera(shared_ptr<Camera> _camera);

    void draw(std::shared_ptr<Scene> _scene);

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


#endif

