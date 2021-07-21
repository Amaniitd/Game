#pragma once
#include "Game.hpp"
#include "Map.hpp"

SDL_Texture *loadingScreen;

void loadScreen()
{
    SDL_Rect rectWall;
    rectWall.w = Game::TILE_SIZE;
    rectWall.h = Game::TILE_SIZE;
    for (int row = 0; row < Game::MAP_HEIGHT; row++)
    {
        for (int col = 0; col < Game::MAP_WIDTH; col++)
        {
            rectWall.x = col * Game::TILE_SIZE;
            rectWall.y = row * Game::TILE_SIZE;
            texture::Draw(loadingScreen, rectWall);
        }
    }
}

void initWelcomeScreen()
{
    loadingScreen = texture::loadTexture("image/Yellow.png");
}