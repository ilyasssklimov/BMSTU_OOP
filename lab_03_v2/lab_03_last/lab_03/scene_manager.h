#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "scene.h"
#include "base_manager.h"


using namespace std;


class SceneManager : public BaseManager
{
public:
    SceneManager();
    ~SceneManager() = default;

    shared_ptr<Scene> get_scene();
    void set_scene(shared_ptr<Scene> _scene);

    shared_ptr<Camera> get_camera();
    void set_camera(long cam_index);

    bool is_camera_exist() { return _camera != nullptr; }

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

#endif // SCENE_MANAGER_H
