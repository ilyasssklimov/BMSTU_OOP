#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <map>

#include "loaders.h"
#include "factory.h"
#include "solution.h"

class BaseRegistrar
{
public:
    BaseRegistrar() = default;
    virtual ~BaseRegistrar() = default;
    virtual void make_registration(Solution &solution) = 0;
};

class Registrar : public BaseRegistrar
{
public:
    Registrar() = default;
    ~Registrar() = default;
    void make_registration(Solution &solution) override;
};

#endif
