#include "scene_command.h"
#include "managers/draw/draw_manager_creator.h"
#include "managers/scene/scene_manager_creator.h"
#include "solution/scene/scene_secretary.h"
#include "solution/scene/scene_solution.h"
#include "managers/load/load_manager_creator.h"


DrawScene::DrawScene(std::shared_ptr<BaseDraw> drawer) : drawer(drawer) {};


void DrawScene::execute()
{
    auto draw_manager = DrawManagerCreator().get_manager();
    auto scene_manager = SceneManagerCreator().get_manager();

    drawer->clear_scene();
    draw_manager->set_drawer(drawer);
    draw_manager->set_camera(scene_manager->get_camera());
    scene_manager->get_scene()->get_composite()->accept(draw_manager);
}


LoadScene::LoadScene(string filename) : filename(filename) {};


void LoadScene::execute()
{
    auto loader = SceneSolution().get_scene_loader();

    auto manager = LoadManagerCreator().get_manager(loader);

    auto scene = std::dynamic_pointer_cast<Scene>(manager->load(filename));
    SceneManagerCreator().get_manager()->set_scene(scene);
}
