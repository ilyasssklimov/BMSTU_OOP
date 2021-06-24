#include "fstream"
#include "model_load_solution.hpp"
#include "errors.hpp"

std::shared_ptr<LoaderCreator> ModelLoadSolution::get_creator()
{
    std::ifstream file(MODEL_CFG_PATH);

    if (!file)
    {
        std::string message = "Error in getting model from config file";
        throw FileError(message);
    }

    int id;
    if (!(file >> id))
    {
        std::string message = "Error in getting model from config file";
        throw FileError(message);
    }

    return SolutionManagerCreator().get_manager()->get_creator(id);
}
