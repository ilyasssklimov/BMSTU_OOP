#include "fstream"
#include "scene_load_solution.h"
#include "errors.h"

shared_ptr<SceneLoaderCreator> SceneLoadSolution::get_creator()
{
    ifstream file(SCENE_CFG_PATH);

    if (!file)
    {
        string message = "Error in getting scene from config file";
        throw file_error(message);
    }

    size_t id;
    if (!(file >> id))
    {
        string message = "Error in getting scene from config file";
        throw file_error(message);
    }

    return SolutionManagerCreator().get_manager()->get_scene_creator(id);
}
