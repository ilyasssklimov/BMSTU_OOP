#include "solution_manager.h"

shared_ptr<SolutionManager> SolutionManagerCreator::get_manager()
{
    if (_manager == nullptr)
        create_manager();

    return _manager;
}

void SolutionManagerCreator::create_manager()
{
    static shared_ptr<SolutionManager> _manager(new SolutionManager());
    this->_manager = _manager;
}

SolutionManager::SolutionManager()
    :reg_maker(shared_ptr<BaseRegistrar>(new Registrar()))
{
    reg_maker->make_registration(_solution);
}


shared_ptr<LoaderCreator> SolutionManager::get_creator(size_t index)
{
    return _solution.get_creator(index);
}

shared_ptr<SceneLoaderCreator> SolutionManager::get_scene_creator(size_t index)
{
    return _solution.get_scene_creator(index);
}

shared_ptr<AbstractFactory> SolutionManager::get_factory(size_t index)
{
    return _solution.get_factory(index);
}
