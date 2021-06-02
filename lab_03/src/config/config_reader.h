#ifndef CONFIG_READER_H
#define CONFIG_READER_H

#include "abstract_config_reader.h"
#include <iostream>
#include <libconfig.h++>
#include <memory>

using namespace std;

#define QT_FILE "../qt.cfg"


class ConfigReader: public AbstractConfigReader
{
public:
    explicit ConfigReader(shared_ptr<string> source);

    void read_config(shared_ptr<string> source = nullptr) override;
    AbstractConfigReader::frames get_frame() override;
    AbstractConfigReader::sources get_load_source() override;

private:
    shared_ptr<libconfig::Config> config;
};

#endif
