#include "abstract_config_reader.h"
#include "config_creator.h"
#include "config_reader.h"


shared_ptr<AbstractConfigReader> ConfigCreator::get_config(shared_ptr<string> source)
{
    if (nullptr == config)
    {
        static shared_ptr<AbstractConfigReader> new_config(new ConfigReader(source));
        config = new_config;
    }
    else if (source)
        config->read_config(source);

    return config;
}
