#ifndef CONFIG_CREATOR_H
#define CONFIG_CREATOR_H


#include <memory>
#include "abstract_config_reader.h"


class ConfigCreator
{
public:
    shared_ptr<AbstractConfigReader> get_config(shared_ptr<string> source = nullptr);

private:
    shared_ptr<AbstractConfigReader> config;
};


#endif
