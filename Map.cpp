#include "Map.hpp"
#include "Texture.hpp"
#include <SDL2/SDL_ttf.h>

Map::Map()
{
    wall = texture::loadTexture("image/[32x32] Dungeon Bricks Shadow.png");
    path = texture::loadTexture("image/Blue.bmp");
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
                texture::Draw(path, src, rectWall);
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
            texture::Draw(path, src, rectWall);
        }
    }
    SDL_Delay(1000);
    TTF_Init();
    TTF_Font *Sans = TTF_OpenFont("FreeSans.ttf", 24); //this opens a font style and sets a size
    if (Sans == NULL)
    {
        fprintf(stderr, "error: font not found\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_Color Color = {232, 63, 63, 0}; // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color

    SDL_Surface *surfaceMessage = TTF_RenderText_Solid(Sans, "WELCOME", Color); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

    SDL_Texture *Message = SDL_CreateTextureFromSurface(Game::renderer, surfaceMessage); //now you can convert it into a texture

    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 112;  //controls the rect's x coordinate
    Message_rect.y = 330;  // controls the rect's y coordinte
    Message_rect.w = 800;  // controls the width of the rect
    Message_rect.h = 300;  // controls the height of the rect

    SDL_RenderCopy(Game::renderer, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture
    //Don't forget to free your surface and texture

    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
    SDL_RenderPresent(Game::renderer);
    TTF_CloseFont(Sans);
    SDL_Delay(2000);
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
                SDL_RenderPresent(Game::renderer);
            }
            else
            {
                texture::Draw(path, src, rectWall);
            }
            SDL_Delay(4);
        }
    }
}