#ifndef SOLUTION_MANAGER_HPP
#define SOLUTION_MANAGER_HPP

#include "solution.hpp"
#include "registration.hpp"
#include "base_manager.hpp"


class SolutionManager : public BaseManager
{
public:
    SolutionManager();

    std::shared_ptr<LoaderCreator> get_creator(size_t index);
    std::shared_ptr<SceneLoaderCreator> get_scene_creator(size_t index);
    std::shared_ptr<AbstractFactory> get_factory(size_t index);

private:
    Solution _solution;
    std::shared_ptr<BaseRegistrationMaker> reg_maker;
};


class SolutionManagerCreator
{
public:
    std::shared_ptr<SolutionManager> get_manager();

private:
    void create_manager();

    std::shared_ptr<SolutionManager> _manager;
};

#endif
