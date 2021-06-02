#ifndef LOAD_SECRETARY_H
#define LOAD_SECRETARY_H


#include <iostream>
#include <memory>
#include "./objects/base_object.h"
#include "loader/base_loader.h"

using namespace std;


class LoadSecretary
{
public:
    LoadSecretary() = default;
    virtual shared_ptr<BaseObject> load(string &filename) = 0;
    virtual void set_loader(shared_ptr<BaseLoader> loader);

    ~LoadSecretary() = default;

private:
    shared_ptr<BaseLoader> loader;
};



#endif
