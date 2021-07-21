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
    void setSource(int x, int y);
    void setDest(int x, int y);
    SDL_Rect getDest() const { return dstRect; }
    SDL_Rect getSource() const { return srcRect; }
    int getDX() const { return dstRect.x; }
    int getDY() const { return dstRect.y; }
    int getDW() const { return dstRect.w; }
    int getDH() const { return dstRect.h; }
    void setId(int i) { id = i; }
    int getId() const { return id; }
    int id;
    int xpos;
    int ypos;
    // SDL_Rect giveCurrentPosition();
    SDL_Rect srcRect;
    SDL_Rect dstRect;
    SDL_Texture *objTexture;
    SDL_Rect tmpRect;

    // SDL_Renderer *renderer;
    // int speed = 4; //should be factor of tile size
};