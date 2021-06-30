#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include "scene.hpp"
#include "base_manager.hpp"


using namespace std;


class SceneManager : public BaseManager
{
public:
    SceneManager();
    ~SceneManager() = default;

    shared_ptr<Scene> get_scene();
    void set_scene(shared_ptr<Scene> _scene);

    shared_ptr<Camera> get_camera();
    void set_camera(int cam_index);

    bool is_camera_exist();

private:
    shared_ptr<Scene> _scene;
    shared_ptr<Camera> _camera;
};


class SceneManagerCreator
{
public:
    shared_ptr<SceneManager> get_manager();

private:
    void create_manager();
    shared_ptr<SceneManager> _manager;
};


#endif
