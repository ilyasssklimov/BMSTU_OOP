#include "secretary.hpp"
#include "solution.hpp"
#include "model_load_solution.hpp"
#include "camera_load_solution.hpp"
#include "scene_load_solution.hpp"

ModelSecretary::ModelSecretary()
{
    std::shared_ptr<LoaderCreator> cr = ModelLoadSolution().get_creator();
    src_loader = std::shared_ptr<SourceLoader>(cr->create_loader());
}

std::shared_ptr<Object> ModelSecretary::load(std::string name)
{
    src_loader->open(name);
    std::shared_ptr<Object> _model = src_loader->load();
    src_loader->close();

    return _model;
}

CameraSecretary::CameraSecretary()
{
    std::shared_ptr<LoaderCreator> cr = CameraLoadSolution().get_creator();
    src_loader = std::shared_ptr<SourceLoader>(cr->create_loader());
}

std::shared_ptr<Object> CameraSecretary::load(std::string name)
{
    src_loader->open(name);
    std::shared_ptr<Object> _camera = src_loader->load();
    src_loader->close();

    return _camera;
}

SceneSecretary::SceneSecretary()
{
    std::shared_ptr<SceneLoaderCreator> cr = SceneLoadSolution().get_creator();
    src_loader = std::shared_ptr<BaseSceneLoader>(cr->create_loader());
}

std::shared_ptr<Scene> SceneSecretary::load(std::string name)
{
    src_loader->open(name);
    std::shared_ptr<Scene> _scene = src_loader->load();
    src_loader->close();

    return _scene;
}
