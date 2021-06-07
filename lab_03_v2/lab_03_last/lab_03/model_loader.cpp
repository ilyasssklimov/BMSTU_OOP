#include "model_file_loader.h"
#include "errors.h"

ModelLoader::ModelLoader()
{
    file = shared_ptr<ifstream>(new ifstream);
    builder = shared_ptr<ModelBuilder>(new modelBuilder);
}

ModelLoader::~ModelLoader()
{
    close();
}

void modelLoader::open(string &name)
{
    if (is_open())
        close();

    file->open(name);
    if (!file)
    {
        string message = "Error while open file";
        throw file_error(message);
    }
}

void modelLoader::close()
{
    try
    {
        file->close();
    } catch (ifstream::failure &error)
    {
        error.what();
    }
}

bool modelLoader::is_open()
{
    return file->is_open();
}

shared_ptr<BaseObject> modelLoader::load()
{
    builder->build();

    vector<Point> points = read_verteces();
    builder->build_verteces(points);

    vector<Edge> edges = read_edges();
    builder->build_edges(edges);

    return dynamic_pointer_cast<BaseObject>(builder->get());
}

vector<Point> modelLoader::read_verteces()
{
    if (!is_open())
    {
        string message = "Error in reading poits from file";
        throw file_error(message);
    }

    vector<Point> verteces;
    long points_count;
    *file >> points_count;

    for (int i = 0; i < points_count; i++)
    {
        double x, y, z;
        *file >> x >> y >> z;
        verteces.push_back(Point(x, y, z));
    }

    return verteces;
}

vector<Edge> modelLoader::read_edges()
{
    if (!is_open())
    {
        string message = "Error in reading edges from file";
        throw file_error(message);
    }

    vector<Edge> edges;
    long edges_count;
    *file >> edges_count;

    for (int i = 0; i < edges_count; i++)
    {
        int point1, point2;
        *file >> point1 >> point2;
        edges.push_back(Edge(point1, point2));
    }

    return edges;
}
