#include "scene.hpp"

Scene::Scene(): models(new Composite), cameras(new Composite) {}


void Scene::add_model(std::shared_ptr<Object> _model)
{
    models->add(_model);
}


void Scene::remove_model(int index)
{
    models->remove(index);
}


void Scene::add_camera(std::shared_ptr<Object> _camera)
{
    cameras->add(_camera);
}


void Scene::remove_camera(int index)
{
    cameras->remove(index);
}
