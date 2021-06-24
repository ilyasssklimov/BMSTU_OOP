#ifndef FACADE_HPP
#define FACADE_HPP

#include "commands.hpp"


using namespace std;


class Facade
{
public:
    void execute(shared_ptr<BaseCommand> command);
};


#endif
