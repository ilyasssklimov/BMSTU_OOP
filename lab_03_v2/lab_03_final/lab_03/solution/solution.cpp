#include "errors.hpp"
#include "solution.hpp"

bool Solution::registration_creator(size_t index, const std::shared_ptr<LoaderCreator> &lc)
{
    return creator_map.insert(callback_creator::value_type(index, lc)).second;
}

bool Solution::registration_scene_creator(size_t index, const std::shared_ptr<SceneLoaderCreator> &lc)
{
    return scene_map.insert(callback_scene_creator::value_type(index, lc)).second;
}

bool Solution::registration_factory(size_t index, const std::shared_ptr<AbstractFactory> &lc)
{
    return factory_map.insert(callback_factory::value_type(index, lc)).second;
}

std::shared_ptr<LoaderCreator> Solution::get_creator(size_t index)
{
    callback_creator::const_iterator it = creator_map.find(index);
    if (it == creator_map.end())
    {
        std::string message = "";
        throw ConfigError(message);
    }

    return it->second;
}

std::shared_ptr<SceneLoaderCreator> Solution::get_scene_creator(size_t index)
{
    callback_scene_creator::const_iterator it = scene_map.find(index);
    if (it == scene_map.end())
    {
        std::string message = "";
        throw ConfigError(message);
    }

    return it->second;
}

std::shared_ptr<AbstractFactory> Solution::get_factory(size_t index)
{
    callback_factory::const_iterator it = factory_map.find(index);
    if (it == factory_map.end())
    {
        std::string message = "";
        throw ConfigError(message);
    }

    return it->second;
}
