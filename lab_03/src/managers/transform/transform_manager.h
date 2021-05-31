#ifndef TRANSFORM_MANAGER_H
#define TRANSFORM_MANAGER_H


#include "../base_manager.h"
#include "./objects/base_object.h"


class TransformManager: public BaseManager
{
public:
    TransformManager() = default;

    static void move_object(const shared_ptr<BaseObject> object, const double dx, const double dy, const double dz);
    static void scale_object(const shared_ptr<BaseObject> object, const double kx, const double ky, const double kz);
    static void turn_object(const shared_ptr<BaseObject> object, const double ox, const double oy, const double oz);

    static void transform_object(const shared_ptr<BaseObject> object, const Vertex &move, const Vertex &scale, const Vertex &turn);

    ~TransformManager() = default;
};

#endif
