#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H

#include <memory>
#include "drawer.h"


using namespace std;


class AbstractFactory
{
public:
    virtual shared_ptr<BaseDrawer> create_ui() const = 0;
};

class QtFactory : public AbstractFactory
{
public:
    shared_ptr<BaseDrawer> create_ui() const override;
};

#endif
