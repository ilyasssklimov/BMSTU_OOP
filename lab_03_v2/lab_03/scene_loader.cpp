#include "scene_file_loader.h"
#include "camera_file_loader.h"
#include "model_file_loader.h"
#include <fstream>

SceneLoader::SceneLoader()
{
    file = shared_ptr<ifstream>(new ifstream);
    builder = shared_ptr<SceneBuilder>(new SceneBuilder);
}

SceneLoader::~SceneLoader()
{
    close();
}

void SceneLoader::open(string &name)
{
    file->open(name);

    if (!is_open())
    {
        string message = "Error in reading edges from file";
        throw file_error(message);
    }
}

shared_ptr<Scene> SceneLoader::load()
{
    builder->build();

    if (!is_open())
    {
        string message = "Error in reading edges from file";
        throw file_error(message);
    }

    load_models();
    load_cameras();

    return shared_ptr<Scene>(builder->get());
}

void SceneLoader::close()
{
    file->close();
}

void SceneLoader::load_models()
{
    size_t models_count;
    if (!(*file >> models_count))
    {
        string message = "Error in reading edges from file";
        throw file_error(message);
    }
    for (size_t i = 0; i < models_count; i++)
    {
        builder->build_model(ModelLoader(file).load());
    }

}

void SceneLoader::load_cameras()
{
    size_t cameras_count;
    if (!(*file >> cameras_count))
    {
        string message = "Error in reading edges from file";
        throw file_error(message);
    }
    for (size_t i = 0; i < cameras_count; i++)
        builder->build_camera(camera_file_loader(file).load());
}

bool SceneLoader::is_open()
{
    return file->is_open();
}
