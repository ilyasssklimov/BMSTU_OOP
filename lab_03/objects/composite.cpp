#include "composite.hpp"
using namespace std;


bool Composite::add(shared_ptr<Object> obj)
{
    objects.push_back(obj);
    return true;
}


bool Composite::remove(int id)
{
    vector<shared_ptr<Object>>::iterator it = objects.begin();
    while (it != objects.end())
    {
        if ((*it)->get_id() == id)
               break;
        it++;
    }

    objects.erase(it + 1);
    return true;
}


void Composite::accept(shared_ptr<Visitor> _visitor)
{
    for (auto obj : objects)
        obj->accept(_visitor);
}


void Composite::reform(shared_ptr<Matrix<double>> reform_mtr)
{
    for (auto obj : objects)
        obj->reform(reform_mtr);
}
