#ifndef LOADER_HPP
#define LOADER_HPP

#include <string>
#include "model.hpp"
#include "builder.hpp"
#include "model_file_loader.hpp"


class LoadSecretary
{
public:
    LoadSecretary() = default;
    ~LoadSecretary() = default;

    virtual std::shared_ptr<Object> load(std::string name) = 0;

protected:
    std::shared_ptr<SourceLoader> src_loader;
};


class ModelSecretary : public LoadSecretary
{
public:
    ModelSecretary();
    ~ModelSecretary() = default;

    std::shared_ptr<Object> load(std::string name) override;
};


class CameraSecretary : public LoadSecretary
{
public:
    CameraSecretary();
    ~CameraSecretary() = default;

    std::shared_ptr<Object> load(std::string name) override;
};


class SceneSecretary
{
public:
    SceneSecretary();
    ~SceneSecretary() = default;

    std::shared_ptr<Scene> load(std::string name);

protected:
    std::shared_ptr<BaseSceneLoader> src_loader;
};

#endif
