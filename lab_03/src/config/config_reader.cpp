#include "config_reader.h"
#include "abstract_config_reader.h"
#include "./exception/exception.h"
#include <time.h>


ConfigReader::ConfigReader(shared_ptr<string> source): AbstractConfigReader(source) {};


void ConfigReader::read_config(shared_ptr<string> source)
{
    config = std::make_shared<libconfig::Config>();

    try
    {
        config->readFile(source ? source->c_str() : source->c_str());
    }
    catch (const libconfig::FileIOException &)
    {
        time_t time_now = time(NULL);
        throw FileError(__FILE__, __LINE__, ctime(&time_now));
    }
    catch (const libconfig::ParseException &)
    {
        time_t time_now = time(NULL);
        throw ParseError(__FILE__, __LINE__, ctime(&time_now));
    }
}

