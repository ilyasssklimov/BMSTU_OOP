#ifndef BASE_SCENE_LOADER_H
#define BASE_SCENE_LOADER_H


#include "../base_loader.h"
#include "objects/base_object.h"
#include "builder/scene/scene_builder.h"


class BaseSceneLoader: BaseLoader
{
public:
    virtual shared_ptr<BaseObject> load(const shared_ptr<SceneBuilder> &builder) = 0;

protected:
    virtual void load_models(shared_ptr<SceneBuilder> builder) = 0;
    virtual void load_cameras(shared_ptr<SceneBuilder> builder) = 0;
};

#endif
