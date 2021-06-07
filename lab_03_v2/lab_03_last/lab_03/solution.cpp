#include "errors.h"
#include "solution.h"

bool Solution::registration_creator(size_t index, const shared_ptr<LoaderCreator> &lc)
{
    return creator_map.insert(map<size_t,  shared_ptr<LoaderCreator>>::value_type(index, lc)).second;
}

bool Solution::registration_scene_creator(size_t index, const shared_ptr<SceneLoaderCreator> &lc)
{
    return scene_map.insert(map<size_t,  shared_ptr<SceneLoaderCreator>>::value_type(index, lc)).second;
}

bool Solution::registration_factory(size_t index, const shared_ptr<AbstractFactory> &lc)
{
    return factory_map.insert(map<size_t,  shared_ptr<AbstractFactory>>::value_type(index, lc)).second;
}

shared_ptr<LoaderCreator> Solution::get_creator(size_t index)
{
    map<size_t,  shared_ptr<LoaderCreator>>::const_iterator it = creator_map.find(index);
    if (it == creator_map.end())
    {
        string message = "";
        throw config_error(message);
    }

    return it->second;
}

shared_ptr<SceneLoaderCreator> Solution::get_scene_creator(size_t index)
{
    map<size_t,  shared_ptr<SceneLoaderCreator>>::const_iterator it = scene_map.find(index);
    if (it == scene_map.end())
    {
        string message = "";
        throw config_error(message);
    }

    return it->second;
}

shared_ptr<AbstractFactory> Solution::get_factory(size_t index)
{
    map<size_t,  shared_ptr<AbstractFactory>>::const_iterator it = factory_map.find(index);
    if (it == factory_map.end())
    {
        string message = "";
        throw config_error(message);
    }

    return it->second;
}
