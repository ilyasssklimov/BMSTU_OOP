#include "secretary.h"
#include "solution.h"
#include "model_load_solution.h"
#include "camera_load_solution.h"
#include "scene_load_solution.h"

ModelSecretary::ModelSecretary()
{
    shared_ptr<LoaderCreator> cr = ModelLoadSolution().get_creator();
    src_loader = shared_ptr<BaseLoader>(cr->create_loader());
}

shared_ptr<BaseObject> ModelSecretary::load(string name)
{
    src_loader->open(name);
    shared_ptr<BaseObject> model = src_loader->load();
    src_loader->close();

    return model;
}

CameraSecretary::CameraSecretary()
{
    shared_ptr<LoaderCreator> cr = CameraLoadSolution().get_creator();
    src_loader = shared_ptr<BaseLoader>(cr->create_loader());
}

shared_ptr<BaseObject> CameraSecretary::load(string name)
{
    src_loader->open(name);
    shared_ptr<BaseObject> camera = src_loader->load();
    src_loader->close();

    return camera;
}

SceneSecretary::SceneSecretary()
{
    shared_ptr<SceneLoaderCreator> cr = SceneLoadSolution().get_creator();
    src_loader = shared_ptr<BaseSceneLoader>(cr->create_loader());
}

shared_ptr<Scene> SceneSecretary::load(string name)
{
    src_loader->open(name);
    shared_ptr<Scene> _scene = src_loader->load();
    src_loader->close();

    return scene;
}
