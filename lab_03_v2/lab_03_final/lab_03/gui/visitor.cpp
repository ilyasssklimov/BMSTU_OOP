#include "visitor.hpp"
#include "transform_matrix.hpp"
#include "model.hpp"
#include "camera.hpp"


Visitor::Visitor(const std::shared_ptr<Camera> &_camera, const std::shared_ptr<BaseDrawer> _drawer)
    :_camera(_camera), _drawer(_drawer)
{
}


void Visitor::visit_model(Model &_model)
{
    if (!_drawer)
    {
        std::string message = "Error while drawing model";
        throw FileError(message);
    }
    if (!_camera)
    {
        std::string message = "Error while drawing model";
        throw FileError(message);
    }

    auto details = _model.get_details();
    auto points = details->get_points();
    auto edges = details->get_edges();

    for (auto &edge : edges)
    {
        _drawer->create_line(get_projection(points[edge.get_first()]),
                          get_projection(points[edge.get_second()]));
    }
}


Point Visitor::get_projection(Point &_point)
{
    Point projection(_point);
    Point move(-_camera->get_position().get_x(), -_camera->get_position().get_y(), 0);
    std::shared_ptr<Matrix<double>> reform_mtr(std::make_shared<MoveMatrix>(_camera->get_position()));

    projection.reform(reform_mtr);

    Point angles = _camera->get_angles().deg_to_rad();
    reform_mtr = std::make_shared<RotateOxMatrix>(-angles.get_x());
    projection.reform(reform_mtr);

    reform_mtr = std::make_shared<RotateOyMatrix>(-angles.get_y());
    projection.reform(reform_mtr);

    reform_mtr = std::make_shared<RotateOzMatrix>(-angles.get_z());
    projection.reform(reform_mtr);

    return projection;
}
