#include "facade.hpp"


using namespace std;


void Facade::execute(shared_ptr<BaseCommand> command)
{
    command->execute();
}
