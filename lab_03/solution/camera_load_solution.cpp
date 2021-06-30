#include "fstream"
#include "camera_load_solution.hpp"
#include "errors.hpp"

std::shared_ptr<LoaderCreator> CameraLoadSolution::get_creator()
{
    std::ifstream file(CAMERA_CFG_PATH);

    if (!file)
    {
        std::string message = "Error in getting camera from config file";
        throw FileError(message);
    }

    size_t id;
    if (!(file >> id))
    {
        std::string message = "Error in getting camera from config file";
        throw FileError(message);
    }

    return SolutionManagerCreator().get_manager()->get_creator(id);
}
