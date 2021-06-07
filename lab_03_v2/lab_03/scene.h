#ifndef SCENE_H
#define SCENE_H

#include "composite.h"
#include "model.h"
#include "camera.h"


class Scene
{
public:
    Scene();
    ~Scene() = default;

    void add_model(shared_ptr<BaseObject> model);
    void remove_model(int index);

    void add_camera(shared_ptr<BaseObject> camera);
    void remove_camera(int index);

    shared_ptr<Composite> get_models() { return models; }
    shared_ptr<Composite> get_cameras() { return cameras; }

private:
    shared_ptr<Composite> models;
    shared_ptr<Composite> cameras;
};

#endif
