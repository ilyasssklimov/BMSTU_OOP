#include "scene_command.h"
#include "managers/draw/draw_manager_creator.h"
#include "managers/scene/scene_manager_creator.h"
#include "solution/scene/scene_secretary.h"


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
    auto secretary = SceneSolution().create_controller();

    auto manager = Load::LoadManagerCreator().create_manager(controller);

    auto scene = std::dynamic_pointer_cast<Scene>(manager->load(_fname));
    SceneManagerCreator().create_manager()->set_scene(scene);
}
