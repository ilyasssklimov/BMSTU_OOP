#ifndef ABSTRACT_CONFIG_READER_H
#define ABSTRACT_CONFIG_READER_H


#include <memory>
using namespace std;


class AbstractConfigReader
{
public:
    enum frames { QT };
    enum sources { FILE };

    explicit AbstractConfigReader(shared_ptr<string> source = nullptr): source(source) {};

    virtual void read_config(shared_ptr<string> source = nullptr) = 0;
    virtual AbstractConfigReader::frames get_frame() = 0;
    virtual AbstractConfigReader::sources get_load_source() = 0;

private:
    shared_ptr<string> source;
};


#endif
