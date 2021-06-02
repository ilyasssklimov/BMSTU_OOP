#include "load_secretary.h"


void LoadSecretary::set_loader(shared_ptr<BaseLoader> loader)
{
    this->loader = loader;
}
