#ifndef SCENE_SECREATARY_H
#define SCENE_SECREATARY_H


#include "../load_secretary.h"
#include "loader/scene/base_scene_loader.h"
#include "builder/scene/scene_builder.h"


using namespace std;


class SceneSecretary: public LoadSecretary
{
public:
    explicit SceneSecretary(shared_ptr<BaseSceneLoader> loader);
    shared_ptr<BaseObject> load(std::string &name) override;
    ~SceneSecretary() = default;

private:
    shared_ptr<SceneBuilder> builder;
    shared_ptr<BaseSceneLoader> loader;
};


#endif
