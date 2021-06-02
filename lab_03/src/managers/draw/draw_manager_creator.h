#ifndef DRAW_MANAGER_CREATOR_H
#define DRAW_MANAGER_CREATOR_H


#include <memory>
#include "draw_manager.h"

using namespace std;


class DrawManagerCreator
{
public:
    shared_ptr<DrawManager> get_manager();

private:
    shared_ptr<DrawManager> manager;
};


#endif
