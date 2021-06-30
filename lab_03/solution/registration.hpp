#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <map>

#include "loaders.hpp"
#include "drawer_factory.hpp"
#include "solution.hpp"


class BaseRegistrationMaker
{
public:
    BaseRegistrationMaker() = default;
    virtual ~BaseRegistrationMaker() = default;
    virtual void make_registration(Solution &_solution) = 0;
};


class RegistrationMaker: public BaseRegistrationMaker
{
public:
    RegistrationMaker() = default;
    ~RegistrationMaker() = default;
    void make_registration(Solution &_solution) override;
};


#endif
