#ifndef BASE_MODEL_LOADER_H
#define BASE_MODEL_LOADER_H


#include "../base_loader.h"
#include "./objects/base_object.h"
#include "./builder/base_builder.h"


class BaseModelLoader: public BaseLoader
{
public:
    virtual shared_ptr<BaseObject> load(shared_ptr<ModelBuilder> builder) = 0;
};

#endif
