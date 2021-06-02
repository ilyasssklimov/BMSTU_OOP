#include "transform_manager_creator.h"


shared_ptr<TransformManager> TransformManagerCreator::get_manager()
{
    if (manager == nullptr)
    {
        static shared_ptr<TransformManager> new_manager(new TransformManager());
        manager = new_manager;
    }

    return manager;
}
