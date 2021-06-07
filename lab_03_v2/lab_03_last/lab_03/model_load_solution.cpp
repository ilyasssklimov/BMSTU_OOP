#include "fstream"
#include "model_load_solution.h"
#include "errors.h"

shared_ptr<LoaderCreator> modelLoadSolution::get_creator()
{
    ifstream file(MODEL_CFG_PATH);

    if (!file)
    {
        string message = "Error in getting model from config file";
        throw file_error(message);
    }

    size_t id;
    if (!(file >> id))
    {
        string message = "Error in getting model from config file";
        throw file_error(message);
    }

    return SolutionManagerCreator().get_manager()->get_creator(id);
}
