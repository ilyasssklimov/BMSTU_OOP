#ifndef LOAD_MANAGER_H
#define LOAD_MANAGER_H


#include "../base_manager.h"
#include "./objects/base_object.h"


class LoadManager: public BaseManager
{
    LoadManager();

    virtual shared_ptr<BaseObject> load(string &filename);
    virtual void set_loader()

    ~LoadManager() = default;
};

#endif
