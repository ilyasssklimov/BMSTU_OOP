#include "scene.h"

Scene::Scene()
    :models(new Composite), cameras(new Composite)
{
}

void Scene::add_model(shared_ptr<BaseObject> model)
{
    models->add(model);
}

void Scene::remove_model(int index)
{
    models->remove(index);
}

void Scene::add_camera(shared_ptr<BaseObject> camera)
{
    cameras->add(camera);
}

void Scene::remove_camera(int index)
{
    cameras->remove(index);
}
