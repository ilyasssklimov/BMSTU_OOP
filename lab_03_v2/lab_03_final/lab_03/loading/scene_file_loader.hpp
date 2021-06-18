#ifndef SCENE_FILE_LOADER_HPP
#define SCENE_FILE_LOADER_HPP

#include "base_loader.hpp"
#include "builder.hpp"


class SceneFileLoader : public BaseSceneLoader
{
public:
    SceneFileLoader();
    ~SceneFileLoader();
    explicit SceneFileLoader(std::shared_ptr<std::ifstream> &file);
    void open(std::string &name) override;
    std::shared_ptr<Scene> load() override;
    void close() override;
    bool is_open() override;

private:
    std::shared_ptr<std::ifstream> file;
    std::shared_ptr<SceneBuilder> builder;

    void load_models();
    void load_cameras();
};

#endif
