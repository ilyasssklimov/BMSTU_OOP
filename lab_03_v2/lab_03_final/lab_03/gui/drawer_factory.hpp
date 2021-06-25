#ifndef ABSTRACT_FACTORY_HPP
#define ABSTRACT_FACTORY_HPP

#include <memory>
#include "drawer.hpp"


using namespace std;


class AbstractFactory
{
public:
    virtual shared_ptr<BaseDrawer> create_ui() const = 0;
};


class QtFactory: public AbstractFactory
{
public:
    shared_ptr<BaseDrawer> create_ui() const override;
};


#endif
