#ifndef SOURCE_LOADER_HPP
#define SOURCE_LOADER_HPP

#include "point.hpp"
#include "edge.hpp"
#include "builder.hpp"
#include "object.hpp"
#include "base_loader.hpp"

#include <vector>
#include <string>
#include <fstream>

class model_file_loader : public BaseModelLoader
{
public:
    model_file_loader();
    explicit model_file_loader(std::shared_ptr<std::ifstream> &file) : file(file) {}
    ~model_file_loader();

    void open(std::string &name) override;
    void close() override;
    bool is_open() override;
    std::shared_ptr<Object> load() override;

private:
    std::vector<Point> read_points();
    std::vector<Edge> read_edges();
    std::shared_ptr<std::ifstream> file;
    std::shared_ptr<ModelBuilder> builder;
};

#endif // SOURCE_LOADER_HPP
