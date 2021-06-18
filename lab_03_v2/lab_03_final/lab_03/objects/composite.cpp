#include "composite.hpp"

bool Composite::add(std::shared_ptr<Object> obj)
{
    objects.push_back(obj);
    return true;
}

bool Composite::remove(int index)
{
    objects.erase(objects.begin() + index);
    return true;
}


void Composite::accept(std::shared_ptr<Visitor> _visitor)
{
    for (auto obj : objects)
        obj->accept(_visitor);
}


void Composite::reform(std::shared_ptr<Matrix<double>> reform_mtr)
{
    for (auto obj : objects)
        obj->reform(reform_mtr);
}
