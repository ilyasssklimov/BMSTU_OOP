#include "commands.hpp"
#include "point.hpp"
#include "transform_matrix.hpp"
#include "load_manager.hpp"
#include "draw_manager.hpp"
#include "reform_manager.hpp"
#include "scene_manager.hpp"


using namespace std;


void LoadModel::execute()
{
    if (!SceneManagerCreator().get_manager()->is_camera_exist())
    {
        string message = "Возникла проблема, так как отсутствует камера";
        throw NoCameraError(message);
    }

    shared_ptr<LoadManager> _load_manager = LoadManagerCreator().get_manager();
    _load_manager->set_secretary(shared_ptr<LoadSecretary>(new ModelSecretary));
    shared_ptr<Object> _model = _load_manager->load(name);
    SceneManagerCreator().get_manager()->get_scene()->add_model(_model);
}


void LoadCamera::execute()
{
    shared_ptr<LoadManager> _load_manager = LoadManagerCreator().get_manager();
    _load_manager->set_secretary(shared_ptr<LoadSecretary>(new CameraSecretary));
    shared_ptr<Object> _camera = _load_manager->load(name);
    SceneManagerCreator().get_manager()->get_scene()->add_camera(_camera);
}


void LoadScene::execute()
{
    shared_ptr<LoadManager> _load_manager = LoadManagerCreator().get_manager();
    _load_manager->set_scene_secretary(shared_ptr<SceneSecretary>());
    shared_ptr<Object> _scene = _load_manager->load(name);
    SceneManagerCreator().get_manager()->get_scene()->add_camera(_scene);
}


void DrawScene::execute()
{
    if (!SceneManagerCreator().get_manager()->is_camera_exist())
    {
        string message = "There is no camera";
        throw NoCameraError(message);
    }

    DrawManagerCreator().get_manager()->set_camera(SceneManagerCreator().get_manager()->get_camera());
    DrawManagerCreator().get_manager()->set_drawer(drawer);

    drawer->clear_scene();

    DrawManagerCreator().get_manager()->draw(SceneManagerCreator().get_manager()->get_scene());
}


void ReformModel::execute()
{
    shared_ptr<Object> _model = SceneManagerCreator().get_manager()->get_scene()->get_models()->get_objects().at(index);

    ReformManagerCreator().get_manager()->shift_model(_model, shift);
    ReformManagerCreator().get_manager()->scale_model(_model, scale);
    ReformManagerCreator().get_manager()->rotate_model(_model, rotate);
}


void ReformCamera::execute()
{
    shared_ptr<Object> _camera = SceneManagerCreator().get_manager()->get_scene()->get_cameras()->get_objects().at(index);
    ReformManagerCreator().get_manager()->shift_model(_camera, shift);

    shared_ptr<Matrix<double>> reform_mtr(make_shared<MoveMatrix>(rotate));
    SceneManagerCreator().get_manager()->get_camera()->rotate(reform_mtr);
}


void RemoveModel::execute()
{
    SceneManagerCreator().get_manager()->get_scene()->remove_model(index);
}


void RemoveCamera::execute()
{
    SceneManagerCreator().get_manager()->get_scene()->remove_camera(index);
}


void SetCamera::execute()
{
    SceneManagerCreator().get_manager()->set_camera(index);
}
