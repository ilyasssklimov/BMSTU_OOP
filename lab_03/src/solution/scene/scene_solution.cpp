#include "scene_solution.h"
#include "config/config_creator.h"
#include "config/abstract_config_reader.h"
#include "loader/scene/

shared_ptr<SceneSecretary>SceneSolution::get_scene_loader()
{
    if (secretary == nullptr)
    {
        static std::shared_ptr<SceneSecretary> new_secretary;

        if (!new_secretary)
        {
            shared_ptr<BaseSceneLoader> loader;
            if (ConfigCreator().get_config()->get_load_source() == AbstractConfigReader::FILE)
                    loader = std::shared_ptr<BaseSceneLoader>(new SceneLoader);

            controller = std::make_shared<SceneLoadController>(loader);
        }

        _controller = controller;
    }

    return _controller;
}

std::shared_ptr<Load::SceneLoadController> Load::SceneLoadControllerCreator::create_controller(const std::shared_ptr<BaseSceneLoader> &loader) {
    if (nullptr == _controller)
        create_instance();

    _controller->set_loader(loader);

    return _controller;
}

void Load::SceneLoadControllerCreator::create_instance() {

}
