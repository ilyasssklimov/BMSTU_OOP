#include "drawer_solution.h"

shared_ptr<AbstractFactory> drawer_solution::get_factory()
{
    ifstream file(SCENE_CFG_PATH);

    if (!file)
    {
        cout << "not file";
        string message = "Error in getting drawer from config file";
        throw file_error(message);
    }

    size_t id;
    if (!(file >> id))
    {
        cout << "file but hren";
        string message = "Error in getting drawer from config file";
        throw file_error(message);
    }

    return solution_manager_creator().get_manager()->get_factory(id);
}
