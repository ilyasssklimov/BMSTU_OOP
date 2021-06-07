#include "factory.h"

shared_ptr<BaseDrawer> QtFactory::create_ui() const
{
    return shared_ptr<BaseDrawer>(new QtDrawer());
}
