#include "transform_manager.h"


void TransformManager::transform_object(const shared_ptr<BaseObject> object, const Vertex &move, const Vertex &scale, const Vertex &turn)
{
    object->transform(move, scale, turn);
}


void TransformManager::move_object(const shared_ptr<BaseObject> object, const double dx, const double dy, const double dz)
{
    Vertex move(dx, dy, dz);
    Vertex scale(1, 1, 1);
    Vertex turn(0, 0, 0);

    object->transform(move, scale, turn);
}


void TransformManager::scale_object(const shared_ptr<BaseObject> object, const double kx, const double ky, const double kz)
{
    Vertex move(0, 0, 0);
    Vertex scale(kx, ky, kz);
    Vertex turn(0, 0, 0);

    object->transform(move, scale, turn);
}


void TransformManager::turn_object(const shared_ptr<BaseObject> object, const double ox, const double oy, const double oz)
{
    Vertex move(0, 0, 0);
    Vertex scale(1, 1, 1);
    Vertex turn(ox, oy, oz);

    object->transform(move, scale, turn);
}
