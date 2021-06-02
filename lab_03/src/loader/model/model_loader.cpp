#include "model_loader.h"
#include "exception/exception.h"
#include <time.h>


ModelLoader::ModelLoader(): file(make_shared<ifstream>()) {}


ModelLoader::ModelLoader(shared_ptr<ifstream> &file)
{
    this->file = file;
}


shared_ptr<BaseObject> ModelLoader::load(shared_ptr<ModelBuilder> builder)
{
    builder->build();

    size_t points_count;
    *file >> points_count;

    double x, y, z;
    for (size_t i = 0; i < points_count; i++)
    {
        *file >> x >> y >> z;
        builder->build_vertex(x, y, z);
    }

    size_t edges_count;
    *file >> edges_count;

    size_t v1, v2;
    for (size_t i = 0; i < edges_count; i++)
    {
        *file >> v1 >> v2;
        builder->build_edge(v1, v2);
    }

    return builder->get();
}


void ModelLoader::open(string &filename)
{
    if (!file)
    {
        time_t time_now = time(NULL);
        throw FileError(__FILE__, __LINE__, ctime(&time_now));
    }

    file->open(filename);

    if (!file)
    {
        time_t time_now = time(NULL);
        throw FileError(__FILE__, __LINE__, ctime(&time_now));
    }
}


void ModelLoader::close()
{
    if (!file)
    {
        time_t time_now = time(NULL);
        throw FileError(__FILE__, __LINE__, ctime(&time_now));
    }

    try
    {
        file->close();
    }
    catch (ifstream::failure &error)
    {
        error.what();
    }
}
