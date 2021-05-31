#ifndef BASE_BUILDER_H
#define BASE_BUILDER_H


#include "./objects/base_object.h"


class BaseBuilder
{
public:
    BaseBuilder() = default;

    virtual bool is_build() const = 0;
    virtual void build() = 0;
    virtual shared_ptr<BaseObject> get() = 0;

    ~BaseBuilder() = default;
};

#endif
