#ifndef BASE_LOADER_H
#define BASE_LOADER_H

#include <string>
#include <memory>

class BaseObject;
class Scene;

class BaseLoader
{
public:
    BaseLoader() = default;
    ~BaseLoader() = default;

    virtual void open(string &name) = 0;
    virtual void close() = 0;
    virtual bool is_open() = 0;
    virtual shared_ptr<BaseObject> load() = 0;
};

class BaseModelLoader : public BaseLoader
{
public:
    BaseModelLoader() = default;
    ~BaseModelLoader() = default;

    virtual void open(string &name) = 0;
    virtual void close() = 0;
    virtual bool is_open() = 0;
    virtual shared_ptr<BaseObject> load() = 0;
};

class BaseCameraLoader : public BaseLoader
{
public:
    BaseCameraLoader() = default;
    ~BaseCameraLoader() = default;

    virtual void open(string &name) = 0;
    virtual void close() = 0;
    virtual bool is_open() = 0;
    virtual shared_ptr<BaseObject> load() = 0;
};

class BaseSceneLoader
{
public:
    BaseSceneLoader() = default;
    ~BaseSceneLoader() = default;

    virtual void open(string &name) = 0;
    virtual void close() = 0;
    virtual bool is_open() = 0;
    virtual shared_ptr<Scene> load() = 0;
};

#endif // BASE_LOADER_H
