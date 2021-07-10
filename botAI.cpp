#include "Game.hpp"
#include "botAI.hpp"
const static int MAP_WIDTH = 35;
const static int MAP_HEIGHT = 25;
void botAI::move()
{
}
void botAI::updatePath()
{
}
void botAI::initializeBot()
{
    int pos = rand() % 600;
    cout << pos << endl;
    int xpos = pos % 25;
    int ypos = pos / 25;
    cout << xpos << " " << ypos << endl;
    // while (map[ypos][xpos])
    // {
    //     int pos = rand() % (MAP_WIDTH * MAP_HEIGHT);
    //     int xpos = pos % MAP_WIDTH;
    //     int ypos = pos / MAP_WIDTH;
    //     cout << xpos << " " << ypos << endl;
    // }
    initObject("image/bots.png", ypos * 32, xpos * 32);
}