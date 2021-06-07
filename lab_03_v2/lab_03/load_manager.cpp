#include "load_manager.h"
#include "errors.h"

shared_ptr<BaseObject> LoadManager::load(const string &name)
{
    if (secretary == nullptr)
    {
        string message = "Error in loading";
        throw no_secretary_error(message);
    }

    return secretary->load(name);
}

shared_ptr<Scene> LoadManager::load_scene(const string &name)
{
    if (scene_secretary == nullptr)
    {
        string message = "Error in loading";
        throw no_secretary_error(message);
    }

    return scene_secretary->load(name);
}

void LoadManager::set_secretary(const shared_ptr<LoadSecretary> &secretary)
{
    this->secretary = secretary;
}

void LoadManager::set_scene_secretary(const shared_ptr<scene_secretary> &secretary)
{
    scene_secretary = secretary;
}

shared_ptr<LoadManager> LoadManagerCreator::get_manager()
{
    if (manager == nullptr)
        create_manager();

    return manager;
}

void LoadManagerCreator::create_manager()
{
    static shared_ptr<LoadManager> manager(new LoadManager());
    this->manager = manager;
}
