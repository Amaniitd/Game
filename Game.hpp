#ifndef Game_hpp
#define Game_hpp
#include <SDL2/SDL.h>
#include <stdio.h>

class Game
{
public:
    Game();
    ~Game();
    bool initialize();
    void update();
    void render();
    void handleEvents();
    void Cleanup();
    bool running() { return isRunning; };
    bool createMap();
    bool loadTiles();
    void createMapSurface();
    bool checkWall(int x, int y);
    SDL_Surface *screenSurface;

    bool isRunning;
    SDL_Window *window;

    SDL_Surface *walls;
    const static int MAP_WIDTH = 32;
    const static int MAP_HEIGHT = 30;
    const static int TILE_SIZE = 32;
    int tiles[MAP_WIDTH * MAP_HEIGHT];
    const int SCREEN_WIDTH = MAP_WIDTH * TILE_SIZE;
    const int SCREEN_HEIGHT = MAP_HEIGHT * TILE_SIZE;
    bool toggle = false;
    int direction = 0;
    SDL_Rect PlayerRect;
    SDL_Rect rectTile;

    SDL_Event event;
};

#endif /* Game_hpp */