#include "facade.h"

void Facade::execute_command(shared_ptr<base_command> command)
{
    command->execute();
}
