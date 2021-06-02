#include "draw_manager_creator.h"


shared_ptr<DrawManager> DrawManagerCreator::get_manager()
{
    if (manager == nullptr)
    {
        static shared_ptr<DrawManager> new_manager(new DrawManager());
        manager = new_manager;
    }

    return manager;
}
