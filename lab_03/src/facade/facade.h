#ifndef FACADE_H
#define FACADE_H

#include "./commands/base_command.h"


class Facade
{
public:
    void execute(BaseCommand &command);
};


#endif
