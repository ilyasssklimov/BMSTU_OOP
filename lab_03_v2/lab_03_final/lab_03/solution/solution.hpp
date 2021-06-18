#ifndef SOLUTION_H
#define SOLUTION_H

#include <map>
#include "loaders.hpp"
#include "drawer_factory.hpp"


class Solution
{
public:
    Solution() = default;
    ~Solution() = default;

    bool registration_creator(size_t index, const std::shared_ptr<LoaderCreator> &lc);
    bool registration_scene_creator(size_t index, const std::shared_ptr<SceneLoaderCreator> &lc);
    bool registration_factory(size_t index, const std::shared_ptr<AbstractFactory> &lc);
    std::shared_ptr<LoaderCreator> get_creator(size_t index);
    std::shared_ptr<SceneLoaderCreator> get_scene_creator(size_t index);
    std::shared_ptr<AbstractFactory> get_factory(size_t index);

private:
    using callback_creator = std::map<size_t, std::shared_ptr<LoaderCreator>>;
    using callback_scene_creator = std::map<size_t, std::shared_ptr<SceneLoaderCreator>>;
    using callback_factory = std::map<size_t, std::shared_ptr<AbstractFactory>>;
    callback_creator creator_map;
    callback_scene_creator scene_map;
    callback_factory factory_map;
};


#endif
