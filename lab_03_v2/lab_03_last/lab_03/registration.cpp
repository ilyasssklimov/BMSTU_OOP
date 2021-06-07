#include "errors.h"
#include "registration.h"
#include "model_file_loader.h"
#include "camera_file_loader.h"
#include "scene_file_loader.h"

void Registrar::make_registration(Solution &_solution)
{

    bool is_registered = _solution.registration_creator(0,
                          shared_ptr<LoaderCreator>(new ConLoaderCreator<ModelLoader>()));
    if (!is_registered)
    {
        string message = "";
        throw config_error(message);
    }

    is_registered = _solution.registration_creator(1,
                          shared_ptr<LoaderCreator>(new ConLoaderCreator<camera_file_loader>()));
    if (!is_registered)
    {
        string message = "";
        throw config_error(message);
    }

    is_registered = _solution.registration_scene_creator(2,
                          shared_ptr<SceneLoaderCreator>(new ConSceneLoaderCreator<SceneLoader>()));
    if (!is_registered)
    {
        string message = "";
        throw config_error(message);
    }

    is_registered = _solution.registration_factory(0,
                          shared_ptr<AbstractFactory>(new QtFactory()));
    if (!is_registered)
    {
        string message = "";
        throw config_error(message);
    }
}
