#include <vector>
#include "../objects/composite/composite.h"
#include "scene.h"


void Scene::add_model(const shared_ptr<BaseObject> &model)
{
    models->add(model);
}


void Scene::delete_model(size_t index)
{
    auto iter = models->begin();
    advance(iter, index);
    models->remove(iter);
}


void Scene::add_camera(const shared_ptr<Camera> &camera)
{
    cameras.push_back(camera);
}


void Scene::delete_camera(size_t index)
{
    auto iter = cameras.begin();
    advance(iter, index);
    cameras.erase(iter);
}


vector<shared_ptr<BaseObject>> Scene::get_models()
{
    return models->get_objects();
}


vector<shared_ptr<Camera>> Scene::get_cameras()
{
    return cameras;
}
