#include "solution_manager.hpp"

std::shared_ptr<SolutionManager> SolutionManagerCreator::get_manager()
{
    if (_manager == nullptr)
        create_manager();

    return _manager;
}

void SolutionManagerCreator::create_manager()
{
    static std::shared_ptr<SolutionManager> _manager(new SolutionManager());
    this->_manager = _manager;
}

SolutionManager::SolutionManager()
    :reg_maker(std::shared_ptr<BaseRegistrationMaker>(new RegistrationMaker()))
{
    reg_maker->make_registration(_solution);
}


std::shared_ptr<LoaderCreator> SolutionManager::get_creator(size_t index)
{
    return _solution.get_creator(index);
}

std::shared_ptr<SceneLoaderCreator> SolutionManager::get_scene_creator(size_t index)
{
    return _solution.get_scene_creator(index);
}

std::shared_ptr<AbstractFactory> SolutionManager::get_factory(size_t index)
{
    return _solution.get_factory(index);
}
