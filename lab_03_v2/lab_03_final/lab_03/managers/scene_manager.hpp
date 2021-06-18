#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include "scene.hpp"
#include "base_manager.hpp"

class scene_manager : public BaseManager
{
public:
    scene_manager();
    ~scene_manager() = default;

    std::shared_ptr<Scene> get_scene();
    void set_scene(std::shared_ptr<Scene> _scene);

    std::shared_ptr<Camera> get_camera();
    void set_camera(int cam_index);

    bool is_camera_exist() { return _camera != nullptr; }

private:
    std::shared_ptr<Scene> _scene;
    std::shared_ptr<Camera> _camera;
};

class scene_manager_creator
{
public:
    std::shared_ptr<scene_manager> get_manager();

private:
    void create_manager();

    std::shared_ptr<scene_manager> _manager;
};

#endif // SCENE_MANAGER_HPP
