#ifndef MODEL_LOAD_SOLUTION_H
#define MODEL_LOAD_SOLUTION_H

#define MODEL_CFG_PATH "./data/model_load.cfg"

#include "solution_manager.hpp"


class ModelLoadSolution
{
public:
    ModelLoadSolution() = default;

    std::shared_ptr<LoaderCreator> get_creator();
};

#endif
