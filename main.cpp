//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include "include\world.h"

int main()
{
    World::Instance()->execute();
    return 0;
}









