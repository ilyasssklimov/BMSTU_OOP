#ifndef ABSTRACT_LOADER_H
#define ABSTRACT_LOADER_H


#include "./objects/base_object.h"
#include "../base_loader.h"


class AbstractLoader
{
public:
    AbstractLoader() = default;
    virtual shared_ptr<BaseObject> load(string &filename) = 0;
    virtual void set_loader(shared_ptr<BaseLoader> loader);

    ~AbstractLoader() = default;

private:
    shared_ptr<BaseLoader> loader;
};


#endif
