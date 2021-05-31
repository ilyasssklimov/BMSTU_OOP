#include "./qt_factory.h"
#include "../qt_draw.h"


unique_ptr<BaseDraw> QtFactory::create_scene()
{
    return unique_ptr<BaseDraw>(new QtDraw(scene));
}
