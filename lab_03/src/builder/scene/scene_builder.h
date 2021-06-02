#ifndef SCENE_BUILDER_H
#define SCENE_BUILDER_H


#include "../base_builder.h"
#include "scene/scene.h"


class SceneBuilder: BaseBuilder
{
public:
    SceneBuilder() = default;

    bool is_build() const override;
    void build() override;
    void build_model(const shared_ptr<BaseObject> &object);
    void build_camera(const shared_ptr<Camera> &camera);

    shared_ptr<BaseObject> get() override;
    shared_ptr<Scene> get_scene();

    ~SceneBuilder() = default;

private:
    shared_ptr<Scene> scene;
};

#endif
