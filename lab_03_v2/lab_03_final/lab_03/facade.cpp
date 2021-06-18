#include "facade.hpp"

void Facade::execute_command(std::shared_ptr<BaseCommand> command)
{
    command->execute();
}
