#include "reform_manager.hpp"
#include "transform_matrix.hpp"
#include "composite.hpp"
#include <math.h>

using namespace std;


shared_ptr<ReformManager> ReformManagerCreator::get_manager()
{
    if (_manager == nullptr)
        create_manager();

    return _manager;
}


void ReformManagerCreator::create_manager()
{
    static shared_ptr<ReformManager> _manager(new ReformManager());
    this->_manager = _manager;
}


void ReformManager::shift_model(shared_ptr<Object> obj, Point &move)
{
    std::shared_ptr<Matrix<double>> reform_mtr(make_shared<MoveMatrix>(move));
    obj->reform(reform_mtr);
}


void ReformManager::scale_model(shared_ptr<Object> obj, Point &scale)
{
    shared_ptr<Matrix<double>> reform_matrix(make_shared<ScaleMatrix>(scale));
    obj->reform(reform_matrix);
}


void ReformManager::rotate_model(shared_ptr<Object> obj, Point &rotate)
{
    Point angles = rotate.deg_to_rad();
    shared_ptr<Matrix<double>> reform_matrix;

    reform_matrix = make_shared<RotateOxMatrix>(angles.get_x());
    obj->reform(reform_matrix);

    reform_matrix = make_shared<RotateOyMatrix>(angles.get_y());
    obj->reform(reform_matrix);

    reform_matrix = make_shared<RotateOzMatrix>(angles.get_z());
    obj->reform(reform_matrix);
}
