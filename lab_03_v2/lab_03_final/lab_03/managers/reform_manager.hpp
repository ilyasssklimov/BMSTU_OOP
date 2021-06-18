#ifndef REFORM_MANAGER_HPP
#define REFORM_MANAGER_HPP

#include <object.hpp>
#include "point.hpp"
#include "base_manager.hpp"

class ReformManager : public BaseManager
{
public:
    void shift_model(std::shared_ptr<Object> obj, Point &move);
    void scale_model(std::shared_ptr<Object> obj, Point &scale);
    void rotate_model(std::shared_ptr<Object> obj, Point &rotate);
};


class ReformManagerCreator
{
public:
    std::shared_ptr<ReformManager> get_manager();

private:
    void create_manager();

    std::shared_ptr<ReformManager> _manager;
};

#endif
