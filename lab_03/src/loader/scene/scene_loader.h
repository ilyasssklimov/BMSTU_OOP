#ifndef SCENE_LOADER_H
#define SCENE_LOADER_H


#include "base_scene_loader.h"
#include "builder/scene/scene_builder.h"


class SceneLoader: public BaseSceneLoader
{
public:
    SceneLoader();
    shared_ptr<BaseObject> load(const shared_ptr<SceneBuilder> &builder) override;

    void open(string &filename) override;
    void close() override;

    ~SceneLoader() override = default;

protected:
    shared_ptr<ifstream> file;

    void load_models(shared_ptr<SceneBuilder> builder) override;
    void load_cameras(shared_ptr<SceneBuilder> builder) override;

};


#endif
