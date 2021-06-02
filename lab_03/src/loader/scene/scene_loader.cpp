#include "scene_loader.h"
#include <time.h>
#include "exception/exception.h"
#include <fstream>
#include "builder/model/model_builder.h"
#include "loader/model/model_loader.h"
#include "builder/camera/camera_builder.h"


SceneLoader::SceneLoader(): file(make_shared<ifstream>()) {};


shared_ptr<BaseObject> SceneLoader::load(const shared_ptr<SceneBuilder> &builder)
{
    builder->build();
    load_models(builder);
    load_cameras(builder);

    return builder->get();
}


void SceneLoader::open(string &filename)
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


void SceneLoader::close()
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


void SceneLoader::load_models(shared_ptr<SceneBuilder> builder)
{
    size_t models_count;
    *file >> models_count;

    auto model_builder = make_shared<ModelBuilder>();
    for (size_t i = 0; i < models_count; ++i)
        builder->build_model(ModelLoader(file).load(model_builder));
}


void SceneLoader::load_cameras(shared_ptr<SceneBuilder> builder)
{
    size_t cameras_count;
    *file >> cameras_count;

    auto camera_builder = make_shared<CameraBuilder>();
    for (size_t i = 0; i < cameras_count; ++i) {
        auto camera = std::dynamic_pointer_cast<Camera>(CameraLoader(file).load(c_builder));
        builder->build_camera(camera);
    }
}
