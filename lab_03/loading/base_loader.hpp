#ifndef BASE_LOADER_HPP
#define BASE_LOADER_HPP

#include <string>
#include <memory>

class Object;
class Scene;


class SourceLoader
{
public:
    SourceLoader() = default;
    ~SourceLoader() = default;

    virtual void open(std::string &name) = 0;
    virtual void close() = 0;
    virtual bool is_open() = 0;
    virtual std::shared_ptr<Object> load() = 0;
};


class BaseModelLoader : public SourceLoader
{
public:
    BaseModelLoader() = default;
    ~BaseModelLoader() = default;

    virtual void open(std::string &name) = 0;
    virtual void close() = 0;
    virtual bool is_open() = 0;
    virtual std::shared_ptr<Object> load() = 0;
};


class BaseCameraLoader : public SourceLoader
{
public:
    BaseCameraLoader() = default;
    ~BaseCameraLoader() = default;

    virtual void open(std::string &name) = 0;
    virtual void close() = 0;
    virtual bool is_open() = 0;
    virtual std::shared_ptr<Object> load() = 0;
};


class BaseSceneLoader
{
public:
    BaseSceneLoader() = default;
    ~BaseSceneLoader() = default;

    virtual void open(std::string &name) = 0;
    virtual void close() = 0;
    virtual bool is_open() = 0;
    virtual std::shared_ptr<Scene> load() = 0;
};

#endif
