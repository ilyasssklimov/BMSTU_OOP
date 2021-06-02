#ifndef SCENE_H
#define SCENE_H


#include <iostream>
#include <memory>
#include "./objects/base_object.h"
#include "./objects/composite/composite.h"
#include "./objects/camera/camera.h"


using namespace std;


class Scene
{
public:
    Scene();

    void add_model(const shared_ptr<BaseObject> &model);
    void delete_model(size_t index);

    void add_camera(const shared_ptr<Camera> &camera);
    void delete_camera(size_t index);

    vector<shared_ptr<BaseObject>> get_models();
    vector<shared_ptr<Camera>> get_cameras();
    std::shared_ptr<Composite> get_composite();

    ~Scene() = default;

protected:
    shared_ptr<Composite> models;
    vector<shared_ptr<Camera>> cameras;

private:
    void accept(shared_ptr<Visitor> visitor);
    void transform(const Vertex &move, const Vertex &scale, const Vertex &turn);
};


#endif
