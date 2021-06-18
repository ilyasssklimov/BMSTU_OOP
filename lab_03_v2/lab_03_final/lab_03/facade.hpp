#ifndef FACADE_HPP
#define FACADE_HPP

#include "commands.hpp"


class Facade
{
public:
    void execute_command(std::shared_ptr<BaseCommand> command);
};


#endif
