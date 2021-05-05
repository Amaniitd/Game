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
    int tiles[600];
    bool checkWall(int x, int y);
    SDL_Surface *screenSurface;

    bool isRunning;
    SDL_Window *window;

    SDL_Surface *walls;
    const int SCREEN_WIDTH = 960;
    const int SCREEN_HEIGHT = 640;
    SDL_Rect rect;

    SDL_Event event;
};

#endif /* Game_hpp */