#ifndef LOADERS_H
#define LOADERS_H

#include "model_file_loader.h"


class LoaderCreator
{
public:
    LoaderCreator() = default;
    virtual ~LoaderCreator() = default;
    virtual shared_ptr<BaseLoader> create_loader() = 0;
};


class SceneLoaderCreator
{
public:
    SceneLoaderCreator() = default;
    virtual ~SceneLoaderCreator() = default;
    virtual shared_ptr<BaseSceneLoader> create_loader() = 0;
};


template <typename T>
class ConLoaderCreator : public LoaderCreator
{
public:
    ConLoaderCreator() = default;
    virtual ~ConLoaderCreator() = default;

    virtual shared_ptr<BaseLoader> create_loader() override;
};


template <typename T>
shared_ptr<BaseLoader> ConLoaderCreator<T>::create_loader()
{
    return shared_ptr<BaseLoader>(new T());
}


template <typename T>
class ConSceneLoaderCreator : public SceneLoaderCreator
{
public:
    ConSceneLoaderCreator() = default;
    virtual ~ConSceneLoaderCreator() = default;

    virtual shared_ptr<BaseSceneLoader> create_loader() override;
};


template <typename T>
shared_ptr<BaseSceneLoader> ConSceneLoaderCreator<T>::create_loader()
{
    return shared_ptr<BaseSceneLoader>(new T());
}


#endif
