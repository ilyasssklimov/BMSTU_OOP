#ifndef SOLUTION_MANAGER_HPP
#define SOLUTION_MANAGER_HPP

#include "solution.hpp"
#include "registration.hpp"
#include "base_manager.hpp"


using namespace std;


class SolutionManager : public BaseManager
{
public:
    SolutionManager();

    shared_ptr<LoaderCreator> get_creator(int index);
    shared_ptr<SceneLoaderCreator> get_scene_creator(int index);
    shared_ptr<AbstractFactory> get_factory(int index);

private:
    Solution _solution;
    shared_ptr<BaseRegistrationMaker> reg_maker;
};


class SolutionManagerCreator
{
public:
    shared_ptr<SolutionManager> get_manager();

private:
    void create_manager();

    shared_ptr<SolutionManager> _manager;
};


#endif
