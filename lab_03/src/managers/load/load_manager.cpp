#include "load_manager.h"


LoadManager::LoadManager()
{
    loader = SceneLoadControllerCreator().create_controller();
}

void Load::LoadManager::set_loader(std::shared_ptr<AbstractLoadController> _loader) { loader = std::move(_loader); }

std::shared_ptr<Object> Load::LoadManager::load(std::string &name) {
    return loader->load(name);
}
