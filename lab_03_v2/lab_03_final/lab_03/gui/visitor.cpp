#include "visitor.hpp"
#include "transform_matrix.hpp"
#include "model.hpp"
#include "camera.hpp"
#include "scene_manager.hpp"

using namespace std;


Visitor::Visitor(const shared_ptr<BaseDrawer> _drawer): _drawer(_drawer) {}


void Visitor::visit_model(Model &_model)
{
    if (!_drawer)
    {
        string message = "Возникла проблема во время отрисовки модели";
        throw FileError(message);
    }
    if (!SceneManagerCreator().get_manager()->get_camera())
    {
        string message = "Возникла проблема, так как отсутствует камера";
        throw FileError(message);
    }

    auto details = _model.get_details();
    auto points = details->get_points();
    auto edges = details->get_edges();

    for (auto &edge : edges)
        _drawer->create_line(get_projection(points[edge.get_first()]), get_projection(points[edge.get_second()]));
}


Point Visitor::get_projection(Point &_point)
{
    Point projection(_point);
    Point move(-SceneManagerCreator().get_manager()->get_camera()->get_position().get_x(),
               -SceneManagerCreator().get_manager()->get_camera()->get_position().get_y(), 0);
    shared_ptr<Matrix<double>> reform_mtr(make_shared<MoveMatrix>(SceneManagerCreator().get_manager()->get_camera()->get_position()));

    projection.reform(reform_mtr);

    Point angles = SceneManagerCreator().get_manager()->get_camera()->get_angles().deg_to_rad();
    reform_mtr = make_shared<RotateOxMatrix>(-angles.get_x());
    projection.reform(reform_mtr);

    reform_mtr = make_shared<RotateOyMatrix>(-angles.get_y());
    projection.reform(reform_mtr);

    reform_mtr = make_shared<RotateOzMatrix>(-angles.get_z());
    projection.reform(reform_mtr);

    return projection;
}
