#ifndef SCENE_HPP
#define SCENE_HPP

#include "composite.hpp"
#include "model.hpp"
#include "camera.hpp"


class Scene
{
public:
    Scene();
    ~Scene() = default;

    void add_model(std::shared_ptr<Object> _model);
    void remove_model(int index);

    void add_camera(std::shared_ptr<Object> _camera);
    void remove_camera(int index);

    std::shared_ptr<Composite> get_models() { return models; }
    std::shared_ptr<Composite> get_cameras() { return cameras; }

private:
    std::shared_ptr<Composite> models;
    std::shared_ptr<Composite> cameras;

    std::shared_ptr<Composite> objects;
};


#endif
