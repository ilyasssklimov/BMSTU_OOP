#ifndef MODEL_LOADER_H
#define MODEL_LOADER_H


#include <fstream>
#include "base_model_loader.h"
#include "./builder/model/model_builder.h"


class ModelLoader: public BaseModelLoader
{
public:
    ModelLoader();
    explicit ModelLoader(shared_ptr<std::ifstream> &file);

    shared_ptr<BaseObject> load(shared_ptr<ModelBuilder> builder) override;
    void open(string &filename) override;
    void close() override;

    ~ModelLoader() override = default;

protected:
     std::shared_ptr<std::ifstream> file;
};

#endif
