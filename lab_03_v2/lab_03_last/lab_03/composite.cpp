#include "composite.h"

bool Composite::add(shared_ptr<BaseObject> obj)
{
    objects.push_back(obj);
    return true;
}

bool Composite::remove(long index)
{
    objects.erase(objects.begin() + index);
    return true;
}

void Composite::accept(shared_ptr<Visitor> visitor)
{
    for (auto obj : objects)
        obj->accept(visitor);
}

void Composite::transform(shared_ptr<Matrix<double>> transform_matrix)
{
    for (auto obj : objects)
        obj->transform(transform_matrix);
}
