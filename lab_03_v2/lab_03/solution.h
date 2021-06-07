#ifndef SOLUTION_H
#define SOLUTION_H

#include <map>
#include "loaders.h"
#include "factory.h"

class Solution
{
public:
    Solution() = default;
    ~Solution() = default;

    bool registration_creator(int index, const shared_ptr<LoaderCreator> &lc);
    bool registration_scene_creator(int index, const shared_ptr<SceneLoaderCreator> &lc);
    bool registration_factory(int index, const shared_ptr<AbstractFactory> &lc);

    shared_ptr<LoaderCreator> get_creator(int index);
    shared_ptr<SceneLoaderCreator> get_scene_creator(int index);
    shared_ptr<AbstractFactory> get_factory(int index);

private:
    map<int,  shared_ptr<LoaderCreator>> creator_map;
    map<int, shared_ptr<SceneLoaderCreator>> scene_map;
    map<int, shared_ptr<AbstractFactory>> factory_map;
};

#endif // SOLUTION_H
