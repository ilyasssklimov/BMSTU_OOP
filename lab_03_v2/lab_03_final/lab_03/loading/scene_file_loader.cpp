#include "scene_file_loader.hpp"
#include "camera_file_loader.hpp"
#include "model_file_loader.hpp"
#include <fstream>

SceneFileLoader::SceneFileLoader()
{
    file = std::shared_ptr<std::ifstream>(new std::ifstream);
    builder = std::shared_ptr<SceneBuilder>(new SceneBuilder);
}

SceneFileLoader::~SceneFileLoader()
{
    close();
}

void SceneFileLoader::open(std::string &name)
{
    file->open(name);

    if (!is_open())
    {
        std::string message = "Error in reading edges from file";
        throw FileError(message);
    }
}

std::shared_ptr<Scene> SceneFileLoader::load()
{
    builder->build();

    if (!is_open())
    {
        std::string message = "Error in reading edges from file";
        throw FileError(message);
    }

    load_models();
    load_cameras();

    return std::shared_ptr<Scene>(builder->get());
}

void SceneFileLoader::close()
{
    file->close();
}

void SceneFileLoader::load_models()
{
    int models_count;
    if (!(*file >> models_count))
    {
        std::string message = "Error in reading edges from file";
        throw FileError(message);
    }
    for (int i = 0; i < models_count; i++)
    {
        builder->build_model(model_file_loader(file).load());
    }

}

void SceneFileLoader::load_cameras()
{
    int cameras_count;
    if (!(*file >> cameras_count))
    {
        std::string message = "Error in reading edges from file";
        throw FileError(message);
    }
    for (int i = 0; i < cameras_count; i++)
        builder->build_camera(camera_file_loader(file).load());
}

bool SceneFileLoader::is_open()
{
    return file->is_open();
}
