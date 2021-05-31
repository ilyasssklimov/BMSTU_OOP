#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H

#include <memory>
#include "../base_draw.h"

using namespace std;


class AbstractFactory
{
public:
    virtual unique_ptr<BaseDraw> create_scene() = 0;
};


#endif
