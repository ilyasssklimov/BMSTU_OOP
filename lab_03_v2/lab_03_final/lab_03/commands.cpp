#include "commands.hpp"
#include "point.hpp"
#include "transform_matrix.hpp"
#include "load_manager.hpp"
#include "draw_manager.hpp"
#include "reform_manager.hpp"
#include "scene_manager.hpp"

void LoadModel::execute()
{
    if (!scene_manager_creator().get_manager()->is_camera_exist())
    {
        std::string message = "There is no camera";
        throw NoCameraError(message);
    }

    std::shared_ptr<LoadManager> _load_manager = LoadManagerCreator().get_manager();
    _load_manager->set_secretary(std::shared_ptr<LoadSecretary>(new ModelSecretary));
    std::shared_ptr<Object> _model = _load_manager->load(name);
    scene_manager_creator().get_manager()->get_scene()->add_model(_model);
}

void LoadCamera::execute()
{
    std::shared_ptr<LoadManager> _load_manager = LoadManagerCreator().get_manager();
    _load_manager->set_secretary(std::shared_ptr<LoadSecretary>(new CameraSecretary));
    std::shared_ptr<Object> _camera = _load_manager->load(name);
    scene_manager_creator().get_manager()->get_scene()->add_camera(_camera);
}

void LoadScene::execute()
{
    std::shared_ptr<LoadManager> _load_manager = LoadManagerCreator().get_manager();
    _load_manager->set_scene_secretary(std::shared_ptr<SceneSecretary>());
    std::shared_ptr<Object> _scene = _load_manager->load(name);
    scene_manager_creator().get_manager()->get_scene()->add_camera(_scene);
}

void DrawScene::execute()
{
    if (!scene_manager_creator().get_manager()->is_camera_exist())
    {
        std::string message = "There is no camera";
        throw NoCameraError(message);
    }

    DrawManagerCreator().get_manager()->set_camera(scene_manager_creator().get_manager()->get_camera());
    DrawManagerCreator().get_manager()->set_drawer(drawer);

    drawer->clear_scene();

    DrawManagerCreator().get_manager()->draw(scene_manager_creator().get_manager()->get_scene());
}

void ReformModel::execute()
{
    std::shared_ptr<Object> _model = scene_manager_creator().get_manager()->get_scene()->get_models()->get_objects().at(index);
    ReformManagerCreator().get_manager()->shift_model(_model, shift);
    ReformManagerCreator().get_manager()->scale_model(_model, scale);
    ReformManagerCreator().get_manager()->rotate_model(_model, rotate);
}

void ReformCamera::execute()
{
    std::shared_ptr<Object> _camera = scene_manager_creator().get_manager()->get_scene()->get_cameras()->get_objects().at(index);
    ReformManagerCreator().get_manager()->shift_model(_camera, shift);

    std::shared_ptr<Matrix<double>> reform_mtr(std::make_shared<MoveMatrix>(rotate));
    scene_manager_creator().get_manager()->get_camera()->rotate(reform_mtr);
}

void RemoveModel::execute()
{
    scene_manager_creator().get_manager()->get_scene()->remove_model(index);
}

void RemoveCamera::execute()
{
    scene_manager_creator().get_manager()->get_scene()->remove_camera(index);
}

void SetCamera::execute()
{
    scene_manager_creator().get_manager()->set_camera(index);
}
