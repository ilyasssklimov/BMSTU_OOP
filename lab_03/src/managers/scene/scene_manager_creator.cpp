#include "scene_manager_creator.h"


shared_ptr<SceneManager> SceneManagerCreator::create_manager()
{
    if (manager == nullptr)
    {
        static shared_ptr<SceneManager> new_manager(new SceneManager());
        manager = new_manager;
    }
    return manager;
}
