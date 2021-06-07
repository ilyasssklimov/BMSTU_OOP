#ifndef SOLUTION_MANAGER_H
#define SOLUTION_MANAGER_H

#include "solution.h"
#include "registration.h"
#include "base_manager.h"


class SolutionManager : public BaseManager
{
public:
    SolutionManager();

    shared_ptr<LoaderCreator> get_creator(int index);
    shared_ptr<SceneLoaderCreator> get_scene_creator(int index);
    shared_ptr<AbstractFactory> get_factory(int index);

private:
    Solution solution;
    shared_ptr<BaseRegistrar> registrar;
};


class SolutionManagerCreator
{
public:
    shared_ptr<SolutionManager> get_manager();

private:
    void create_manager();
    shared_ptr<SolutionManager> manager;
};

#endif // SOLUTION_MANAGER_H
