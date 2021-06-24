#include "camera_file_loader.hpp"
#include <fstream>


using namespace std;


camera_file_loader::camera_file_loader()
{
    file = shared_ptr<ifstream>(new ifstream);
    builder = shared_ptr<CameraBuilder>(new CameraBuilder);
}


camera_file_loader::~camera_file_loader()
{
    close();
}


void camera_file_loader::open(string &name)
{
    file->open(name);

    if (!is_open())
    {
        string message = "Проблема во время чтения ребер из файла";
        throw FileError(message);
    }
}


shared_ptr<Object> camera_file_loader::load()
{
    builder->build();

    if (!is_open())
    {
        string message = "Error in reading edges from file";
        throw FileError(message);
    }

    double x, y, z;
    if (!(*file >> x >> y >> z))
    {
        string message = "Error in reading edges from file";
        throw FileError(message);
    }
    builder->build_pos(x, y, z);

    if (!(*file >> x >> y >> z))
    {
        string message = "Error in reading edges from file";
        throw FileError(message);
    }
    builder->build_angles(x, y, z);

    return dynamic_pointer_cast<Object>(builder->get());
}


void camera_file_loader::close()
{
    file->close();
}


bool camera_file_loader::is_open()
{
    return file->is_open();
}
