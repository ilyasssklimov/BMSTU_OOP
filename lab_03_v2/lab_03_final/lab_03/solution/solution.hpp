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

    bool registration_creator(int index, const std::shared_ptr<LoaderCreator> &lc);
    bool registration_scene_creator(int index, const std::shared_ptr<SceneLoaderCreator> &lc);
    bool registration_factory(int index, const std::shared_ptr<AbstractFactory> &lc);
    std::shared_ptr<LoaderCreator> get_creator(int index);
    std::shared_ptr<SceneLoaderCreator> get_scene_creator(int index);
    std::shared_ptr<AbstractFactory> get_factory(int index);

private:
    using callback_creator = std::map<int, std::shared_ptr<LoaderCreator>>;
    using callback_scene_creator = std::map<int, std::shared_ptr<SceneLoaderCreator>>;
    using callback_factory = std::map<int, std::shared_ptr<AbstractFactory>>;
    callback_creator creator_map;
    callback_scene_creator scene_map;
    callback_factory factory_map;
};


#endif
