#ifndef LOAD_MANAGER_H
#define LOAD_MANAGER_H

#include "base_object.h"
#include "secretary.h"
#include "base_manager.h"


using namespace std;


class LoadManager : public BaseManager
{
public:
    LoadManager() = default;
    shared_ptr<BaseObject> load(const string &name);
    shared_ptr<Scene> load_scene(const string &name);
    void set_secretary(const shared_ptr<LoadSecretary> &secretary);
    void set_scene_secretary(const shared_ptr<scene_secretary> &secretary);

private:
    shared_ptr<LoadSecretary> secretary;
    shared_ptr<scene_secretary> scene_secretary;
};


class LoadManagerCreator
{
public:
    shared_ptr<LoadManager> get_manager();

private:
    void create_manager();
    shared_ptr<LoadManager> manager;
};

#endif
