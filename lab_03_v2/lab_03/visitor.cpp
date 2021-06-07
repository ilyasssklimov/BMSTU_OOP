#include "visitor.h"
#include "transform_matrix.h"
#include "model.h"
#include "camera.h"

Visitor::Visitor(const shared_ptr<Camera> &camera, const shared_ptr<BaseDrawer> drawer)
    :_camera(_camera), drawer(_drawer)
{
}

void Visitor::visit_model(Model &model)
{
    if (!drawer)
    {
        string message = "Error while drawing model";
        throw file_error(message);
    }
    if (!camera)
    {
        string message = "Error while drawing model";
        throw file_error(message);
    }

    auto Elements = model.get_elements();
    auto points = Elements->get_points();
    auto edges = Elements->get_edges();

    for (auto &Edge : edges)
    {
        drawer->draw_line(get_projection(points[edge.get_first()]),
                          get_projection(points[edge.get_second()]));
    }
}

Point Visitor::get_projection(Point &_point)
{
    Point projection(_point);
    Point move(-camera->get_position().get_x(), -camera->get_position().get_y(), 0);
    shared_ptr<Matrix<double>> transform_matrix(make_shared<MoveMatrix>(camera->get_position()));

    projection.transform(transform_matrix);

    Point angles = camera->get_angles().deg_to_rad();
    transform_matrix = make_shared<RotateOxMatrix>(-angles.get_x());
    projection.transform(transform_matrix);

    transform_matrix = make_shared<RotateOyMatrix>(-angles.get_y());
    projection.transform(transform_matrix);

    transform_matrix = make_shared<RotateOzMatrix>(-angles.get_z());
    projection.transform(transform_matrix);

    return projection;
}
