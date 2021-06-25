#include "scene.hpp"

using namespace std;


Scene::Scene()
{
    objects = shared_ptr<Object>(new Composite);
}


void Scene::add_object(shared_ptr<Object> new_object)
{
    inc_id();
    objects->add(new_object);
}


void Scene::remove_object(int id)
{
    objects->remove(id);
}


shared_ptr<Object> Scene::get_objects() const
{
    return objects;
}


shared_ptr<Object> Scene::get_object(int id)
{
    vector<shared_ptr<Object>>::iterator it = objects->begin();
    while (it != objects->end())
    {
        if ((*it)->get_id() == id)
               return *it;
        it++;
    }
    return shared_ptr<Object>();
}


void Scene::inc_id()
{
    id++;
}


int Scene::get_last_id()
{
    return id;
}


/*
void Scene::add_model(shared_ptr<Object> _model)
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
*/
