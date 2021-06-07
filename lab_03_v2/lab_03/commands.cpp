#include "commands.h"
#include "point.h"
#include "transform_matrix.h"
#include "load_manager.h"
#include "draw_manager.h"
#include "transform_manager.h"
#include "scene_manager.h"


void LoadModel::execute()
{
    if (!SceneManagerCreator().get_manager()->is_camera_exist())
    {
        string message = "There is no camera";
        throw no_camera_error(message);
    }

    shared_ptr<LoadManager> load_manager = LoadManagerCreator().get_manager();
    load_manager->set_secretary(shared_ptr<LoadSecretary>(new modelSecretary));
    shared_ptr<BaseObject> model = load_manager->load(name);
    SceneManagerCreator().get_manager()->get_scene()->add_model(model);
}


void LoadCamera::execute()
{
    shared_ptr<LoadManager> load_manager = LoadManagerCreator().get_manager();
    _load_manager->set_secretary(shared_ptr<LoadSecretary>(new CameraSecretary));
    shared_ptr<BaseObject> camera = load_manager->load(name);
    SceneManagerCreator().get_manager()->get_scene()->add_camera(camera);
}


void LoadScene::execute()
{
    shared_ptr<LoadManager> _load_manager = LoadManagerCreator().get_manager();
    load_manager->set_scene_secretary(shared_ptr<SceneSecretary>());
    shared_ptr<BaseObject> scene = load_manager->load(name);
    SceneManagerCreator().get_manager()->get_scene()->add_camera(scene);
}


void DrawScene::execute()
{
    if (!SceneManagerCreator().get_manager()->is_camera_exist())
    {
        string message = "There is no camera";
        throw no_camera_error(message);
    }

    DrawManagerCreator().get_manager()->set_camera(SceneManagerCreator().get_manager()->get_camera());
    DrawManagerCreator().get_manager()->set_drawer(drawer);

    drawer->clear_scene();

    DrawManagerCreator().get_manager()->draw(SceneManagerCreator().get_manager()->get_scene());
}


void TransformModel::execute()
{
    shared_ptr<BaseObject> model = SceneManagerCreator().get_manager()->get_scene()->get_models()->get_objects().at(index);
    TransformManagerCreator().get_manager()->shift_model(model, shift);
    TransformManagerCreator().get_manager()->scale_model(model, scale);
    TransformManagerCreator().get_manager()->rotate_model(model, rotate);
}


void TransformCamera::execute()
{
    shared_ptr<BaseObject> camera = SceneManagerCreator().get_manager()->get_scene()->get_cameras()->get_objects().at(index);
    TransformManagerCreator().get_manager()->shift_model(camera, shift);

    shared_ptr<Matrix<double>> transform_mtr(make_shared<MoveMatrix>(rotate));
    SceneManagerCreator().get_manager()->get_camera()->rotate(transform_mtr);
}


void DeleteModel::execute()
{
    SceneManagerCreator().get_manager()->get_scene()->remove_model(index);
}


void DeleteCamera::execute()
{
    SceneManagerCreator().get_manager()->get_scene()->remove_camera(index);
}


void set_camera::execute()
{
    SceneManagerCreator().get_manager()->set_camera(index);
}
