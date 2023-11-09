#include "Application.h"
#include <Engine/Core/Log.h>

i32 main(){
    LOG_DEBUG("Test");
    LOG_INFO("Test");
    LOG_WARNING("Test");
    LOG_ERROR("Test");

    ASSERT(1 == false);

    Application app;
    app.Run();
}