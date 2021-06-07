#ifndef REFORM_MANAGER_H
#define REFORM_MANAGER_H

#include <base_object.h>
#include "point.h"
#include "base_manager.h"


class TransformManager : public BaseManager
{
public:
    void shift_model(shared_ptr<BaseObject> obj, Point &move);
    void scale_model(shared_ptr<BaseObject> obj, Point &scale);
    void rotate_model(shared_ptr<BaseObject> obj, Point &turn);
};

class TransformManagerCreator
{
public:
    shared_ptr<TransformManager> get_manager();

private:
    void create_manager();
    shared_ptr<TransformManager> manager;
};

#endif
