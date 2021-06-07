#include "fstream"
#include "camera_load_solution.h"
#include "errors.h"



shared_ptr<LoaderCreator> CameraLoadSolution::get_creator()
{
    ifstream file(CAMERA_CFG_PATH);

    if (!file)
    {
        string message = "Error in getting camera from config file";
        throw file_error(message);
    }

    size_t id;
    if (!(file >> id))
    {
        string message = "Error in getting camera from config file";
        throw file_error(message);
    }

    return SolutionManagerCreator().get_manager()->get_creator(id);
}
