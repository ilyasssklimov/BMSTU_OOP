#ifndef MODEL_SOLUTION_H
#define MODEL_SOLUTION_H

#include "model_secretary.h"


class ModelSolution
{
public:
    std::shared_ptr<ModelSecretary> get_model_loader();
    std::shared_ptr<ModelSecretary> get_model_loader(const shared_ptr<BaseModelLoader> &loader);

private:
    std::shared_ptr<ModelSecretary> secretary;
};


#endif
