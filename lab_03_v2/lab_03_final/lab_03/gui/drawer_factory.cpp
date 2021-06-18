#include "drawer_factory.hpp"


std::shared_ptr<BaseDrawer> QtFactory::create_ui() const
{
    return std::shared_ptr<BaseDrawer>(new QtDrawer());
}
