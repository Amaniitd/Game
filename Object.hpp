#pragma once
#include "Game.hpp"

class Object
{
public:
    void initObject(const char *filename, int x, int y);

    void Update();
    void Render();
    void setSource(int x, int y, int w, int h);
    void setDest(int x, int y, int w, int h);

private:
    int xpos;
    int ypos;
    // SDL_Rect giveCurrentPosition();
    SDL_Rect srcRect;
    SDL_Rect dstRect;
    SDL_Texture *objTexture;

    // SDL_Renderer *renderer;
    // int speed = 4; //should be factor of tile size
};