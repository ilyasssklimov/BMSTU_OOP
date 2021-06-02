#ifndef ABSTRACT_CONFIG_READER_H
#define ABSTRACT_CONFIG_READER_H


#include <memory>
using namespace std;


class AbstractConfigReader
{
public:
    enum frames { QT };

    explicit AbstractConfigReader(shared_ptr<string> source = nullptr): source(source) {};

    virtual void read_config(shared_ptr<string> source = nullptr) = 0;
    virtual AbstractConfigReader::frames get_frames() = 0;

private:
    shared_ptr<string> source;
};


#endif
