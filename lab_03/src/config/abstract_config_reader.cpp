#include "abstract_config_reader.h"
#include "config_reader.h"


AbstractConfigReader::frames ConfigReader::get_frame() {
    if (!config)
        read_config(make_shared<string>(QT_FILE));

    auto &root = config->getRoot();
    string frame;

    try
    {
        const auto &ui = root["graphics"];

        if (!ui.lookupValue("frame", frame))
            frame = "qt";

    }
    catch (const libconfig::SettingNotFoundException &) {
        return QT;
    }

    if ("qt" == frame)
    {
        return QT;
    }
    else
    {
        return QT;
    }
}


AbstractConfigReader::sources ConfigReader::get_load_source() {
    if (!config)
        read_config(make_shared<string>(QT_FILE));

    auto &root = config->getRoot();
    string frame;

    try
    {
        const auto &ui = root["storage"];

        if (!ui.lookupValue("load_source", frame))
            frame = "file";

    }
    catch (const libconfig::SettingNotFoundException &) {
        return FILE;
    }

    if ("file" == frame)
    {
        return FILE;
    }
    else
    {
        return FILE;
    }
}
