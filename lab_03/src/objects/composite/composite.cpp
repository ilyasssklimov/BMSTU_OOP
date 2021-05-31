#include "composite.h"


Composite::Composite(const shared_ptr<BaseObject> &object)
{
    objects.push_back(object);
}


Composite::Composite(const vector<shared_ptr<BaseObject>> &vector)
{
    objects = vector;
}


void Composite::add(const shared_ptr<BaseObject> &object)
{
    objects.push_back(object);
}


void Composite::remove(const vector<shared_ptr<BaseObject>>::iterator &it)
{
    objects.erase(it);
}


bool Composite::is_visible() const
{
    return false;
}


void Composite::transform(const Vertex &move, const Vertex &scale, const Vertex &turn)
{
    for (const auto &element: objects)
        element->transform(move, scale, turn);
}


void Composite::accept(shared_ptr<Visitor> visitor)
{
    for (const auto &element: objects)
        element->accept(visitor);
}


vector<shared_ptr<BaseObject>>::iterator Composite::begin()
{
    return objects.begin();
}


vector<shared_ptr<BaseObject>>::iterator Composite::end()
{
    return objects.end();
}


vector<shared_ptr<BaseObject>> &Composite::get_objects()
{
    return objects;
}
