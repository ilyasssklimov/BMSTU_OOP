#include "model_file_loader.hpp"
#include "errors.hpp"

model_file_loader::model_file_loader()
{
    file = std::shared_ptr<std::ifstream>(new std::ifstream);
    builder = std::shared_ptr<ModelBuilder>(new ModelBuilder);
}

model_file_loader::~model_file_loader()
{
    close();
}

void model_file_loader::open(std::string &name)
{
    if (is_open())
        close();

    file->open(name);
    if (!file)
    {
        std::string message = "Error while open file";
        throw FileError(message);
    }
}

void model_file_loader::close()
{
    try
    {
        file->close();
    } catch (std::ifstream::failure &error)
    {
        error.what();
    }
}

bool model_file_loader::is_open()
{
    return file->is_open();
}

std::shared_ptr<Object> model_file_loader::load()
{
    builder->build();

    std::vector<Point> points = read_points();
    builder->build_points(points);

    std::vector<Edge> edges = read_edges();
    builder->build_edges(edges);

    return std::dynamic_pointer_cast<Object>(builder->get());
}

std::vector<Point> model_file_loader::read_points()
{
    if (!is_open())
    {
        std::string message = "Error in reading poits from file";
        throw FileError(message);
    }

    std::vector<Point> points;
    int points_count;
    *file >> points_count;

    for (int i = 0; i < points_count; i++)
    {
        double x, y, z;
        *file >> x >> y >> z;
        points.push_back(Point(x, y, z));
    }

    return points;
}

std::vector<Edge> model_file_loader::read_edges()
{
    if (!is_open())
    {
        std::string message = "Error in reading edges from file";
        throw FileError(message);
    }

    std::vector<Edge> edges;
    int edges_count;
    *file >> edges_count;

    for (int i = 0; i < edges_count; i++)
    {
        int point1, point2;
        *file >> point1 >> point2;
        edges.push_back(Edge(point1, point2));
    }

    return edges;
}
