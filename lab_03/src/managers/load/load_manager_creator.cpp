#include "load_manager_creator.h"


shared_ptr<LoadManager> LoadManagerCreator::get_manager()
{
    if (manager == nullptr)
    {
        static shared_ptr<LoadManager> new_manager(new LoadManager());
        manager = new_manager;
    }

    return manager;
}


shared_ptr<LoadManager> LoadManagerCreator::get_manager(const shared_ptr<LoadSecretary> &loader)
{
    if (manager == nullptr)
    {
        static shared_ptr<LoadManager> new_manager(new LoadManager());
        manager = new_manager;
    }

    manager->set_loader(loader);

    return manager;
}

