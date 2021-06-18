#ifndef ABSTRACT_FACTORY_HPP
#define ABSTRACT_FACTORY_HPP

#include <memory>
#include "drawer.hpp"


class AbstractFactory
{
public:
    virtual std::shared_ptr<BaseDrawer> create_ui() const = 0;
};


class QtFactory : public AbstractFactory
{
public:
    std::shared_ptr<BaseDrawer> create_ui() const override;
};

#endif
