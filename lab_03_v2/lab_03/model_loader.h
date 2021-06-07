#ifndef SOURCE_LOADER_H
#define SOURCE_LOADER_H

#include "point.h"
#include "edge.h"
#include "builder.h"
#include "base_object.h"
#include "base_loader.h"

#include <vector>
#include <string>
#include <fstream>

class ModelLoader : public BaseModelLoader
{
public:
    ModelLoader();
    explicit ModelLoader(shared_ptr<ifstream> &file) : file(file) {}
    ~ModelLoader();

    void open(string &name) override;
    void close() override;
    bool is_open() override;
    shared_ptr<BaseObject> load() override;

private:
    vector<Point> read_verteces();
    vector<Edge> read_edges();
    shared_ptr<ifstream> file;
    shared_ptr<ModelBuilder> builder;
};

#endif
