#include "model_secretary.h"
#include "./exception/exception.h"
#include <time.h>


ModelSecretary::ModelSecretary(shared_ptr<BaseModelLoader> loader): builder(new ModelBuilder), loader(loader) {};


shared_ptr<BaseObject> ModelSecretary::load(string &filename)
{
    loader->open(filename);

    shared_ptr<BaseObject> model;
    try
    {
        model = loader->load(builder);
    }
    catch (exception &error)
    {
        time_t time_now = time(NULL);
        throw ReadModelError(__FILE__, __LINE__, ctime(&time_now));
    }

    loader->close();

    return model;
}
