#ifndef LOAD_MANAGER_H
#define LOAD_MANAGER_H


#include "../base_manager.h"
#include "./objects/base_object.h"
#include "./solution/load_secretary.h"


class LoadManager: public BaseManager
{
public:
    LoadManager();

    virtual shared_ptr<BaseObject> load(string &filename);
    virtual void set_loader(shared_ptr<LoadSecretary> loader);

    ~LoadManager() = default;

private:
    shared_ptr<LoadSecretary> loader;
};

#endif
