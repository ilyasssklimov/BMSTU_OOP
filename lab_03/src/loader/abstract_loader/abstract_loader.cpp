#include "abstract_loader.h"


void AbstractLoader::set_loader(shared_ptr<BaseLoader> loader)
{
    this->loader = loader;
}
