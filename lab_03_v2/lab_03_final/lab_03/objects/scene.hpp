#ifndef SCENE_HPP
#define SCENE_HPP

#include "composite.hpp"
#include "model.hpp"
#include "camera.hpp"


using namespace std;


class Scene
{
public:
    Scene();
    ~Scene() = default;

    void add_object(shared_ptr<Object> new_object);
    void remove_object(int id);

    shared_ptr<Object> get_objects() const;
    shared_ptr<Object> get_object(int id);

    void inc_id();
    int get_last_id();

    // void add_model(shared_ptr<Object> _model);
    // void remove_model(int index);

    // void add_camera(shared_ptr<Object> _camera);
    // void remove_camera(int index);

    // shared_ptr<Composite> get_models() { return models; }
    // shared_ptr<Composite> get_cameras() { return cameras; }

private:
    // shared_ptr<Composite> models;
    // shared_ptr<Composite> cameras;

    shared_ptr<Object> objects;
    int id = 0;
};


#endif
