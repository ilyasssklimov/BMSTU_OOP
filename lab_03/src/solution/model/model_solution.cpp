#include "model_solution.h"
#include "config/config_creator.h"
#include "config/abstract_config_reader.h"
#include "loader/model/model_loader.h"


shared_ptr<ModelSecretary> ModelSolution::get_model_loader()
{
    if (secretary == nullptr)
    {
        static std::shared_ptr<ModelSecretary> new_secretary;

        if (!new_secretary)
        {
            shared_ptr<BaseModelLoader> loader;
            if (ConfigCreator().get_config()->get_load_source() == AbstractConfigReader::FILE)
                loader = shared_ptr<BaseModelLoader>(new ModelLoader);

            secretary = make_shared<ModelSecretary>(loader);
        }
        secretary = new_secretary;
    }

    return secretary;
}


shared_ptr<ModelSecretary> ModelSolution::get_model_loader(const shared_ptr<BaseModelLoader> &loader)
{
    if (secretary == nullptr)
    {
        static std::shared_ptr<ModelSecretary> new_secretary;

        if (!new_secretary)
        {
            shared_ptr<BaseModelLoader> loader;
            if (ConfigCreator().get_config()->get_load_source() == AbstractConfigReader::FILE)
                loader = shared_ptr<BaseModelLoader>(new ModelLoader);

            secretary = make_shared<ModelSecretary>(loader);
        }
        secretary = new_secretary;
    }

    secretary->set_loader(loader);

    return secretary;
}
