#include "load_manager.hpp"
#include "errors.hpp"

std::shared_ptr<Object> LoadManager::load(const std::string &name)
{
    if (secretary == nullptr)
    {
        std::string message = "Error in loading";
        throw NoSecretaryError(message);
    }

    return secretary->load(name);
}

std::shared_ptr<Scene> LoadManager::load_scene(const std::string &name)
{
    if (scn_secr == nullptr)
    {
        std::string message = "Error in loading";
        throw NoSecretaryError(message);
    }

    return scn_secr->load(name);
}

void LoadManager::set_secretary(const std::shared_ptr<LoadSecretary> &secretary)
{
    this->secretary = secretary;
}

void LoadManager::set_scene_secretary(const std::shared_ptr<SceneSecretary> &secretary)
{
    scn_secr = secretary;
}

std::shared_ptr<LoadManager> LoadManagerCreator::get_manager()
{
    if (_manager == nullptr)
        create_manager();

    return _manager;
}

void LoadManagerCreator::create_manager()
{
    static std::shared_ptr<LoadManager> _manager(new LoadManager());
    this->_manager = _manager;
}
