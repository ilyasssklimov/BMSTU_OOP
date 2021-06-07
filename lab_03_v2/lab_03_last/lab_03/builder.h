#ifndef BASE_BUILDER_H
#define BASE_BUILDER_H

#include "scene.h"


using namespace std;


class ModelBuilder
{
public:
    ModelBuilder() = default;
    ~ModelBuilder() = default;

    bool is_build();
    void build();
    void build_points(vector<Point> pt);
    void build_edges(vector<Edge> ed);

    shared_ptr<BaseObject> get();

private:
    shared_ptr<Elements> _details;
};

class SceneBuilder
{
public:
    SceneBuilder() = default;
    ~SceneBuilder() = default;

    bool is_build();
    void build();
    void build_model(const shared_ptr<BaseObject> &_model);
    void build_camera(const shared_ptr<BaseObject> &_camera);

    shared_ptr<Scene> get();

private:
    shared_ptr<Scene> _scene;
};

class camera_builder
{
public:
    camera_builder() = default;
    ~camera_builder() = default;

    bool is_build();
    void build();
    void build_pos(double x, double y, double z);
    void build_angles(double ox, double oy, double oz);

    shared_ptr<BaseObject> get();

private:
    Point position;
    Point angles;
};

#endif // BASE_BUILDER_H
