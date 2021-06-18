#include "fstream"
#include "scene_load_solution.hpp"
#include "errors.hpp"

std::shared_ptr<SceneLoaderCreator> SceneLoadSolution::get_creator()
{
    std::ifstream file(SCENE_CFG_PATH);

    if (!file)
    {
        std::string message = "Error in getting scene from config file";
        throw FileError(message);
    }

    size_t id;
    if (!(file >> id))
    {
        std::string message = "Error in getting scene from config file";
        throw FileError(message);
    }

    return SolutionManagerCreator().get_manager()->get_scene_creator(id);
}
