#include "object.hpp"


bool Object::add(shared_ptr<Object>)
{
    return false;
}


bool Object::remove(int)
{
    return false;
}


vector<shared_ptr<Object>>::iterator Object::begin()
{
    return vector<shared_ptr<Object>>::iterator();
}


vector<shared_ptr<Object>>::iterator Object::end()
{
    return vector<shared_ptr<Object>>::iterator();
}


vector<shared_ptr<Object>>::const_iterator Object::cbegin() const
{
    return vector<shared_ptr<Object>>::const_iterator();
}


vector<shared_ptr<Object>>::const_iterator Object::cend() const
{
    return vector<shared_ptr<Object>>::const_iterator();
}



void Object::set_id(int id)
{
    this->id = id;
}


int Object::get_id()
{
    return id;
}
