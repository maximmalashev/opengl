#include "engine/common/application.h"

int main()
{
    engine::Application application;

    application.InitializeWindow(720, 720, "OpenGL Window");
    application.Start();

    return 0;
}