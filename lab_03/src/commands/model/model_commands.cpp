#include <iostream>
#include "./commands/model/model_commands.h"
#include "./solution/model/model_solution.h"
#include "./managers/load/load_manager_creator.h"
#include "./managers/scene/scene_manager_creator.h"


using namespace std;


LoadModel::LoadModel(string filename): filename(filename) {};


void LoadModel::execute()
{
    auto loader = ModelSolution().get_model_loader();
    auto manager = LoadManagerCreator().get_manager(loader);
    auto model = manager->load(filename);

    SceneManagerCreator().get_manager()->get_scene()->add_model(model);
}



CountModel::CountModel(shared_ptr<size_t> &count) : count(count) {};


void CountModel::execute()
{
    (*count) = SceneManagerCreator().get_manager()->get_scene()->get_models().size();
}
