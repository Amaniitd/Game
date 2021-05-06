#pragma once

#include "Game.hpp"

class texture
{

public:
    static SDL_Texture *loadTexture(const char *filename);
    static void Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dst);
};