#ifndef TRANSFORM_MANAGER_CREATOR_H
#define TRANSFORM_MANAGER_CREATOR_H


#include "transform_manager.h"


class TransformManagerCreator
{
public:
    shared_ptr<TransformManager> create_manager();

private:
    shared_ptr<TransformManager> manager;
};


#endif
