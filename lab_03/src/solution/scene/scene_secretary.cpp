#include "scene_secretary.h"



SceneSecretary::SceneSecretary(shared_ptr<BaseSceneLoader> loader): builder(new SceneBuilder), loader(loader){};


