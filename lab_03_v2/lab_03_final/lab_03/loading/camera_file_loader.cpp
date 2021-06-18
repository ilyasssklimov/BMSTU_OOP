#include "camera_file_loader.hpp"
#include <fstream>

camera_file_loader::camera_file_loader()
{
    file = std::shared_ptr<std::ifstream>(new std::ifstream);
    builder = std::shared_ptr<CameraBuilder>(new CameraBuilder);
}

camera_file_loader::~camera_file_loader()
{
    close();
}

void camera_file_loader::open(std::string &name)
{
    file->open(name);

    if (!is_open())
    {
        std::string message = "Error in reading edges from file";
        throw FileError(message);
    }
}

std::shared_ptr<Object> camera_file_loader::load()
{
    builder->build();

    if (!is_open())
    {
        std::string message = "Error in reading edges from file";
        throw FileError(message);
    }

    double x, y, z;
    if (!(*file >> x >> y >> z))
    {
        std::string message = "Error in reading edges from file";
        throw FileError(message);
    }
    builder->build_pos(x, y, z);

    if (!(*file >> x >> y >> z))
    {
        std::string message = "Error in reading edges from file";
        throw FileError(message);
    }
    builder->build_angles(x, y, z);

    return std::dynamic_pointer_cast<Object>(builder->get());
}

void camera_file_loader::close()
{
    file->close();
}

bool camera_file_loader::is_open()
{
    return file->is_open();
}
