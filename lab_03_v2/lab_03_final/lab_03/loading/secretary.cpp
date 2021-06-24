#include "secretary.hpp"
#include "solution.hpp"
#include "model_load_solution.hpp"
#include "camera_load_solution.hpp"
#include "scene_load_solution.hpp"


using namespace std;


ModelSecretary::ModelSecretary()
{
    shared_ptr<LoaderCreator> creator = ModelLoadSolution().get_creator();
    src_loader = shared_ptr<SourceLoader>(creator->create_loader());
}


shared_ptr<Object> ModelSecretary::load(string name)
{
    src_loader->open(name);
    shared_ptr<Object> _model = src_loader->load();
    src_loader->close();

    return _model;
}


CameraSecretary::CameraSecretary()
{
    shared_ptr<LoaderCreator> creator = CameraLoadSolution().get_creator();
    src_loader = shared_ptr<SourceLoader>(creator->create_loader());
}


shared_ptr<Object> CameraSecretary::load(string name)
{
    src_loader->open(name);
    shared_ptr<Object> _camera = src_loader->load();
    src_loader->close();

    return _camera;
}


SceneSecretary::SceneSecretary()
{
    shared_ptr<SceneLoaderCreator> creator = SceneLoadSolution().get_creator();
    src_loader = std::shared_ptr<BaseSceneLoader>(creator->create_loader());
}


shared_ptr<Scene> SceneSecretary::load(string name)
{
    src_loader->open(name);
    shared_ptr<Scene> _scene = src_loader->load();
    src_loader->close();

    return _scene;
}
