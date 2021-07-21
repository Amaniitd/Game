#pragma once
#include "Game.hpp"
#include "Texture.hpp"
#include <SDL2/SDL_ttf.h>
#include "randomMaze.hpp"
SDL_Rect src, dst;
SDL_Texture *wall;
SDL_Texture *path;
SDL_Texture *mapTexture;

void Map()
{
    wall = texture::loadTexture("image/[32x32] Dungeon Bricks Shadow.png");
    path = texture::loadTexture("image/Blue.png");
    src.x = 0;
    src.y = 0;
    src.w = 32;
    src.h = 32;
}

bool loadMap(int map[Game::MAP_HEIGHT][Game::MAP_WIDTH])
{
    // ifstream tileFile("tiles.txt");
    // if (tileFile.is_open())
    // {
    //     for (int row = 0; row < MAP_HEIGHT; row++)
    //     {
    //         for (int col = 0; col < MAP_WIDTH; col++)
    //         {
    //             tileFile >> map[row][col];
    //         }
    //     }
    //     tileFile.close();
    //     return 1;
    // }
    // return 0;

    return Maze(map);
}

void drawMap(int map[Game::MAP_HEIGHT][Game::MAP_WIDTH])
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
            int currentTile = map[row][col];
            if (currentTile > 0)
            {
                texture::Draw(wall, src, rectWall);
            }
            else
            {
                texture::Draw(path, rectWall);
            }
        }
    }
}

void drawMapWithDelay(int map[Game::MAP_HEIGHT][Game::MAP_WIDTH])
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
            int currentTile = map[row][col];
            if (currentTile > 0)
            {
                texture::Draw(wall, src, rectWall);
            }
            else
            {
                texture::Draw(path, rectWall);
            }
        }
        SDL_RenderPresent(Game::renderer);
        SDL_Delay(80);
    }
}