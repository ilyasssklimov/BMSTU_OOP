#include "scene_builder.h"


bool SceneBuilder::is_build() const
{
    return scene != nullptr;
}


void SceneBuilder::build()
{
    scene = make_shared<Scene>();
}


void SceneBuilder::build_model(const std::shared_ptr<BaseObject> &object)
{
    if (is_build())
        scene->add_model(object);
}


void SceneBuilder::build_camera(const shared_ptr<Camera> &camera)
{
    if (!is_build())
        scene->add_camera(camera);
}


shared_ptr<Scene> SceneBuilder::get_scene()
{
    return scene;
}
