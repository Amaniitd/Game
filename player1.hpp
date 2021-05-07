#pragma once
#include "Object.hpp"

class player1 : Object
{

public:
    void handleEvents();
    // bool checkWall(int x, int y);

private:
    SDL_Event event;
    bool toggle = false;
    int direction = 0;
    const static int MAP_WIDTH = 32;
    const static int MAP_HEIGHT = 30;
    const static int TILE_SIZE = 32;
    const int SCREEN_WIDTH = MAP_WIDTH * TILE_SIZE;
    const int SCREEN_HEIGHT = MAP_HEIGHT * TILE_SIZE;
};