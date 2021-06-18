#include "drawer_solution.hpp"

std::shared_ptr<AbstractFactory> DrawerSolution::get_factory()
{
    std::ifstream file(SCENE_CFG_PATH);

    if (!file)
    {
        std::string message = "Error in getting drawer from config file";
        throw FileError(message);
    }

    size_t id;
    if (!(file >> id))
    {
        std::string message = "Error in getting drawer from config file";
        throw FileError(message);
    }

    return SolutionManagerCreator().get_manager()->get_factory(id);
}
