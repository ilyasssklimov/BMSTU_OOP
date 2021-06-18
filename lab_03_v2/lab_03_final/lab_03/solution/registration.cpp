#include "errors.hpp"
#include "registration.hpp"
#include "model_file_loader.hpp"
#include "camera_file_loader.hpp"
#include "scene_file_loader.hpp"

void RegistrationMaker::make_registration(Solution &_solution)
{

    bool is_registered = _solution.registration_creator(0,
                          std::shared_ptr<LoaderCreator>(new ConLoaderCreator<model_file_loader>()));
    if (!is_registered)
    {
        std::string message = "";
        throw ConfigError(message);
    }

    is_registered = _solution.registration_creator(1,
                          std::shared_ptr<LoaderCreator>(new ConLoaderCreator<camera_file_loader>()));
    if (!is_registered)
    {
        std::string message = "";
        throw ConfigError(message);
    }

    is_registered = _solution.registration_scene_creator(2,
                          std::shared_ptr<SceneLoaderCreator>(new ConSceneLoaderCreator<SceneFileLoader>()));
    if (!is_registered)
    {
        std::string message = "";
        throw ConfigError(message);
    }

    is_registered = _solution.registration_factory(0,
                          std::shared_ptr<AbstractFactory>(new QtFactory()));
    if (!is_registered)
    {
        std::string message = "";
        throw ConfigError(message);
    }
}
