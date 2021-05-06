#pragma once
#include "Game.hpp"

class Map
{

public:
    Map();
    ~Map();

    bool loadMap();
    void drawMap();
    void drawMapWithDelay();

    SDL_Rect src, dst;
    SDL_Texture *wall;
    SDL_Texture *path;
    SDL_Texture *mapTexture;
    int map[30][32];
    const static int MAP_WIDTH = 32;
    const static int MAP_HEIGHT = 30;
    const static int TILE_SIZE = 32;
    const static int SCREEN_WIDTH = MAP_WIDTH * TILE_SIZE;
    const static int SCREEN_HEIGHT = MAP_HEIGHT * TILE_SIZE;
};