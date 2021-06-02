#ifndef LOAD_MANAGER_CREATOR_H
#define LOAD_MANAGER_CREATOR_H


#include <memory>
#include "load_manager.h"
#include "solution/load_secretary.h"


using namespace std;


class LoadManagerCreator
{
public:
    shared_ptr<LoadManager> get_manager();
    std::shared_ptr<LoadManager> get_manager(const shared_ptr<LoadSecretary> &loader);

private:
    shared_ptr<LoadManager> manager;
};

#endif
