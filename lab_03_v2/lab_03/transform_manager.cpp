#include "transform_manager.h"
#include "transform_matrix.h"
#include <math.h>

shared_ptr<TransformManager> TransformManagerCreator::get_manager()
{
    if (_manager == nullptr)
        create_manager();

    return _manager;
}

void TransformManagerCreator::create_manager()
{
    static shared_ptr<TransformManager> _manager(new TransformManager());
    this->_manager = _manager;
}

void TransformManager::shift_model(shared_ptr<BaseObject> obj, Point &move)
{
    shared_ptr<Matrix<double>> transform_mtr(make_shared<MoveMatrix>(move));
    obj->transform(transform_mtr);
}

void TransformManager::scale_model(shared_ptr<BaseObject> obj, Point &scale)
{
    shared_ptr<Matrix<double>> transform_mtr(make_shared<ScaleMatrix>(scale));
    obj->transform(transform_mtr);
}

void TransformManager::rotate_model(shared_ptr<BaseObject> obj, Point &rotate)
{
    Point angles = rotate.deg_to_rad();
    shared_ptr<Matrix<double>> transform_mtr(make_shared<RotateOxMatrix>(angles.get_x()));
    obj->transform(transform_mtr);

    transform_mtr = make_shared<RotateOyMatrix>(angles.get_y());
    obj->transform(transform_mtr);

    transform_mtr = make_shared<RotateOzMatrix>(angles.get_z());
    obj->transform(transform_mtr);
}
