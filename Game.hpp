#pragma once
#ifndef Game_hpp
#define Game_hpp
#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>
#include "Texture.hpp"
#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;
#include "Audio.hpp"

class Game
{
public:
    Game();
    ~Game();
    bool initialize();
    void initBots();
    void update();
    void render();
    void handleEvents();
    void Cleanup();
    bool running() { return isRunning; };
    bool createMap();
    bool loadTiles();
    void triggerAttack();
    void createMapSurface();
    bool checkWall(int x, int y);
    bool isRunning;
    Audio intro;
    int speed;
    bool l, r, u, d, fall;
    bool l2, r2, u2, d2;
    int idoll, idolr, runl, runr;
    int idolu, idold, runu, rund;
    int die;
    bool attack = false;
    int attackl, attackr, attacku, attackd;
    SDL_Window *window;
    inline static SDL_Renderer *renderer;
    SDL_Texture *wallTexture;
    const static int MAP_WIDTH = 35;
    const static int MAP_HEIGHT = 25;
    const static int TILE_SIZE = 32;
    const static int scoreboardWidth = 300;
    int map[MAP_HEIGHT][MAP_WIDTH];
    static int tiles[MAP_WIDTH * MAP_HEIGHT];
    const static int SCREEN_WIDTH = MAP_WIDTH * TILE_SIZE + scoreboardWidth;
    const static int SCREEN_HEIGHT = MAP_HEIGHT * TILE_SIZE;
    SDL_Rect rectTile;
    SDL_Event event;
};

#endif /* Game_hpp */