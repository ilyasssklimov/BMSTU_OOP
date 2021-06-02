#ifndef CONFIG_READER_H
#define CONFIG_READER_H

#include "abstract_config_reader.h"
#include <iostream>
#include <memory>
using namespace std;


class ConfigReader: public AbstractConfigReader
{
public:
    explicit ConfigReader(shared_ptr<string> source);

    void read_config(shared_ptr<string> source = nullptr) override;
    AbstractConfigReader::frames get_frames() override;


private:
    shared_ptr<libconfig::Config> config;
};



#endif
