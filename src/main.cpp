
#include <iostream>
#include "gameWorld.h"


int main()
{
    GameWorld world = GameWorld();
    while (true)
    {
        if (!world.performSetup())
        {
            std::cerr << "Game setup failed!" << std::endl;
            return 1;
        }
        if (!world.runGame())
        {
            return 0;
        }
    }
    return 0;
}
