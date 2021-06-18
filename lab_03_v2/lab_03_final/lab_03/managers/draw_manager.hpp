#ifndef DRAW_MANAGER_HPP
#define DRAW_MANAGER_HPP

#include <memory>
#include "visitor.hpp"
#include "scene.hpp"
#include "base_manager.hpp"


class DrawManager : public BaseManager
{
public:
    DrawManager() = default;
    ~DrawManager() = default;

    void set_drawer(std::shared_ptr<BaseDrawer> _drawer);
    void set_camera(std::shared_ptr<Camera> _camera);

    void draw(std::shared_ptr<Scene> _scene);

private:
    std::shared_ptr<Visitor> _visitor;
    std::shared_ptr<BaseDrawer> _drawer;
    std::shared_ptr<Camera> _camera;
};


class DrawManagerCreator
{
public:
    std::shared_ptr<DrawManager> get_manager();

private:
    void create_manager();

    std::shared_ptr<DrawManager> _manager;
};


#endif

