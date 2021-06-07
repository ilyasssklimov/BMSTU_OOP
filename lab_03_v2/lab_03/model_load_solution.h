#ifndef MODEL_LOAD_SOLUTION_H
#define MODEL_LOAD_SOLUTION_H

#define MODEL_CFG_PATH "./data/model_load.cfg"

#include "solution_manager.h"

class ModelLoadSolution
{
public:
    ModelLoadSolution() = default;

    shared_ptr<LoaderCreator> get_creator();
};

#endif
