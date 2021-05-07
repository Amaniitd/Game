#include "Map.hpp"
#include "Texture.hpp"
#include <SDL2/SDL_ttf.h>

Map::Map()
{
    wall = texture::loadTexture("image/[32x32] Dungeon Bricks Shadow.png");
    path = texture::loadTexture("image/Blue.png");
    src.x = 0;
    src.y = 0;
    src.w = 32;
    src.h = 32;
}

bool Map::loadMap()
{
    ifstream tileFile("tiles.txt");
    if (tileFile.is_open())
    {
        for (int row = 0; row < MAP_HEIGHT; row++)
        {
            for (int col = 0; col < MAP_WIDTH; col++)
            {
                tileFile >> map[row][col];
            }
        }
        tileFile.close();
        return 1;
    }
    return 0;
}

void Map::drawMap()
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

void Map::drawMapWithDelay()
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
