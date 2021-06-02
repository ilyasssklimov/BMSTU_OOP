#include "base_object.h"


bool BaseObject::is_visible() const
{
    return false;
};


vector<shared_ptr<BaseObject>>::iterator BaseObject::begin()
{
    return vector<shared_ptr<BaseObject>>::iterator();
};


vector<shared_ptr<BaseObject>>::iterator BaseObject::end()
{
    return vector<shared_ptr<BaseObject>>::iterator();
};
