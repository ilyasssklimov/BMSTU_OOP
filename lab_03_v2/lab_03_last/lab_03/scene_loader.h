#ifndef SCENE_FILE_LOADER_H
#define SCENE_FILE_LOADER_H

#include "base_loader.h"
#include "builder.h"


using namespace std;


class SceneLoader: public BaseSceneLoader
{
public:
    SceneLoader();
    ~SceneLoader();
    explicit SceneLoader(shared_ptr<ifstream> &file);

    void open(string &name) override;
    shared_ptr<Scene> load() override;
    void close() override;
    bool is_open() override;

private:
    shared_ptr<ifstream> file;
    shared_ptr<SceneBuilder> builder;

    void load_models();
    void load_cameras();
};

#endif
