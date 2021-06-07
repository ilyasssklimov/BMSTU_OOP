#ifndef CAMERA_FILE_LOADER_H
#define CAMERA_FILE_LOADER_H

#include "base_loader.h"
#include "builder.h"


using namespace std;


class camera_file_loader : public BaseCameraLoader
{
public:
    camera_file_loader();
    ~camera_file_loader();
    explicit camera_file_loader(shared_ptr<ifstream> &file) : file(file) {}
    void open(string &name) override;
    shared_ptr<BaseObject> load() override;
    void close() override;
    bool is_open() override;

private:
    shared_ptr<ifstream> file;
    shared_ptr<camera_builder> builder;
};

#endif // CAMERA_FILE_LOADER_H
