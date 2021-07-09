#pragma once
#include "Game.hpp"
#include "Map.hpp"

SDL_Texture *loadingScreen;

void loadScreen()
{
    SDL_Rect rectWall;
    rectWall.w = TILE_SIZE;
    rectWall.h = TILE_SIZE;
    for (int row = 0; row < MAP_HEIGHT; row++)
    {
        for (int col = 0; col < MAP_WIDTH; col++)
        {
            rectWall.x = col * TILE_SIZE;
            rectWall.y = row * TILE_SIZE;
            texture::Draw(loadingScreen, rectWall);
        }
    }
}

void initWelcomeScreen()
{
    loadingScreen = texture::loadTexture("image/Yellow.png");
}