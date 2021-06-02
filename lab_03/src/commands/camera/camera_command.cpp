#include "./commands/camera/camera_command.h"
#include "./managers/scene/scene_manager_creator.h"



CountCamera::CountCamera(shared_ptr<size_t> &count) : count(count) {}


void CountCamera::execute()
{
    (*count) = SceneManagerCreator().get_manager()->get_scene()->get_cameras().size();
}
