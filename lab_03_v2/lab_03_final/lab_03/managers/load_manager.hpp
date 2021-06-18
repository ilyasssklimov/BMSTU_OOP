#ifndef LOAD_MANAGER_HPP
#define LOAD_MANAGER_HPP

#include "object.hpp"
#include "secretary.hpp"
#include "base_manager.hpp"


class LoadManager : public BaseManager
{
public:
    LoadManager() = default;
    std::shared_ptr<Object> load(const std::string &name);
    std::shared_ptr<Scene> load_scene(const std::string &name);
    void set_secretary(const std::shared_ptr<LoadSecretary> &secretary);
    void set_scene_secretary(const std::shared_ptr<SceneSecretary> &secretary);

private:
    std::shared_ptr<LoadSecretary> secretary;
    std::shared_ptr<SceneSecretary> scn_secr;
};


class LoadManagerCreator
{
public:
    std::shared_ptr<LoadManager> get_manager();

private:
    void create_manager();

    std::shared_ptr<LoadManager> _manager;
};


#endif
