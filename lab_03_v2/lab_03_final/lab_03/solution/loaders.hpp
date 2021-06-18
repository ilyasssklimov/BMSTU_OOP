#ifndef LOADERS_H
#define LOADERS_H

#include "model_file_loader.hpp"


class LoaderCreator
{
public:
    LoaderCreator() = default;
    virtual ~LoaderCreator() = default;
    virtual std::shared_ptr<SourceLoader> create_loader() = 0;
};


class SceneLoaderCreator
{
public:
    SceneLoaderCreator() = default;
    virtual ~SceneLoaderCreator() = default;
    virtual std::shared_ptr<BaseSceneLoader> create_loader() = 0;
};


template <typename T>
class ConLoaderCreator : public LoaderCreator
{
public:
    ConLoaderCreator() = default;
    virtual ~ConLoaderCreator() = default;

    virtual std::shared_ptr<SourceLoader> create_loader() override;
};


template <typename T>
std::shared_ptr<SourceLoader> ConLoaderCreator<T>::create_loader()
{
    return std::shared_ptr<SourceLoader>(new T());
}


template <typename T>
class ConSceneLoaderCreator : public SceneLoaderCreator
{
public:
    ConSceneLoaderCreator() = default;
    virtual ~ConSceneLoaderCreator() = default;

    virtual std::shared_ptr<BaseSceneLoader> create_loader() override;
};


template <typename T>
std::shared_ptr<BaseSceneLoader> ConSceneLoaderCreator<T>::create_loader()
{
    return std::shared_ptr<BaseSceneLoader>(new T());
}


#endif
