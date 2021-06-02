#ifndef MODEL_SECRETARY_H
#define MODEL_SECRETARY_H


#include "../load_secretary.h"
#include "./loader/model/base_model_loader.h"



class ModelSecretary: public LoadSecretary
{
public:
    explicit ModelSecretary(shared_ptr<BaseModelLoader> loader);
    shared_ptr<BaseObject> load(string &filename) override;
    ~ModelSecretary() = default;

private:
    shared_ptr<ModelBuilder> builder;
    shared_ptr<BaseModelLoader> loader;
};


#endif
