#ifndef BASE_BUILDER_HPP
#define BASE_BUILDER_HPP

#include "scene.hpp"

class ModelBuilder
{
public:
    ModelBuilder() = default;
    ~ModelBuilder() = default;

    bool is_build();
    void build();
    void build_points(std::vector<Point> pt);
    void build_edges(std::vector<Edge> ed);

    std::shared_ptr<Object> get();

private:
    std::shared_ptr<Details> _details;
};


class SceneBuilder
{
public:
    SceneBuilder() = default;
    ~SceneBuilder() = default;

    bool is_build();
    void build();
    void build_model(const std::shared_ptr<Object> &_model);
    void build_camera(const std::shared_ptr<Object> &_camera);

    std::shared_ptr<Scene> get();

private:
    std::shared_ptr<Scene> _scene;
};

class CameraBuilder
{
public:
    CameraBuilder() = default;
    ~CameraBuilder() = default;

    bool is_build();
    void build();
    void build_pos(double x, double y, double z);
    void build_angles(double ox, double oy, double oz);

    std::shared_ptr<Object> get();

private:
    Point position;
    Point angles;
};

#endif
