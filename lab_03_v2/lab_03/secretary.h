#ifndef LOADER_H
#define LOADER_H

#include <string>
#include "model.h"
#include "builder.h"
#include "model_file_loader.h"


class LoadSecretary
{
public:
    LoadSecretary() = default;
    ~LoadSecretary() = default;

    virtual shared_ptr<BaseObject> load(string name) = 0;

protected:
    shared_ptr<BaseLoader> src_loader;
};

class ModelSecretary : public LoadSecretary
{
public:
    ModelSecretary();
    ~ModelSecretary() = default;

    shared_ptr<BaseObject> load(string name) override;
};

class CameraSecretary : public LoadSecretary
{
public:
    CameraSecretary();
    ~CameraSecretary() = default;

    shared_ptr<BaseObject> load(string name) override;
};

class SceneSecretary
{
public:
    SceneSecretary();
    ~SceneSecretary() = default;

    shared_ptr<Scene> load(string name);

protected:
    shared_ptr<BaseSceneLoader> src_loader;
};

#endif
