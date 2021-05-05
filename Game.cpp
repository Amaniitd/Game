#include "Game.hpp"
#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

Game::Game()
{
    PlayerRect.x = TILE_SIZE;
    PlayerRect.y = TILE_SIZE;
    PlayerRect.w = TILE_SIZE;
    PlayerRect.h = TILE_SIZE;
    isRunning = true;
    rectTile.x = 0;
    rectTile.y = 0;
    rectTile.h = TILE_SIZE;
    rectTile.w = TILE_SIZE;
}
Game::~Game()
{
}

bool Game::initialize()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }
    //Create window
    window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }
    screenSurface = SDL_GetWindowSurface(window);
    return 1;
}

bool Game::createMap()
{
    return true;
}
bool Game::loadTiles()
{
    ifstream tileFile("tiles.txt");
    if (tileFile.is_open())
    {
        int tile;
        int i = 0;
        while (tileFile >> tile)
        {
            tiles[i] = tile;
            i++;
        }
        return 1;
        tileFile.close();
    }
    return 0;
}

void Game::createMapSurface()
{
    int row = 0;
    int column = 0;
    SDL_Rect rectWall;
    rectWall.w = TILE_SIZE;
    rectWall.h = TILE_SIZE;
    SDL_Surface *wallImg = SDL_LoadBMP("image/[32x32] Dungeon Bricks Shadow.bmp");
    SDL_Surface *pathImg = SDL_LoadBMP("image/Blue.bmp");
    if (wallImg == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
    }
    walls = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, TILE_SIZE, 0, 0, 0, 0);
    while (row < SCREEN_HEIGHT / TILE_SIZE)
    {
        while (column < SCREEN_WIDTH / TILE_SIZE)
        {
            rectWall.x = column * TILE_SIZE;
            rectWall.y = row * TILE_SIZE;
            int currentTile = tiles[row * SCREEN_WIDTH / TILE_SIZE + column];
            Uint32 color;
            if (currentTile > 0)
            {
                SDL_BlitSurface(wallImg, &rectTile, walls, &rectWall);
            }
            else
            {
                SDL_BlitSurface(pathImg, &rectTile, walls, &rectWall);
            }
            column++;
        }
        column = 0;
        row++;
    }
    if (walls == NULL)
    {
        SDL_Log("SDL_CreateRGBSurface() failed: %s", SDL_GetError());
        exit(1);
    }
}

bool Game::checkWall(int x, int y)
{
    return tiles[(y / TILE_SIZE) * (SCREEN_WIDTH / TILE_SIZE) + x / TILE_SIZE];
}

void Game::Cleanup()
{
    //Destroy window
    SDL_DestroyWindow(window);
    SDL_FreeSurface(walls);

    //Quit SDL subsystems
    SDL_Quit();
    cout << "Game cleaned" << endl;
}

void Game::render()
{
    SDL_BlitSurface(walls, NULL, screenSurface, NULL);
    SDL_Surface *playerImg = SDL_LoadBMP("image/player2.bmp");
    SDL_Surface *playerImgx = SDL_LoadBMP("image/player1x.bmp");
    if (toggle)
    {
        SDL_BlitSurface(playerImgx, &rectTile, screenSurface, &PlayerRect);
    }
    else
    {
        SDL_BlitSurface(playerImg, &rectTile, screenSurface, &PlayerRect);
    }
    SDL_UpdateWindowSurface(window);
}

void Game::handleEvents()
{

    while (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_QUIT)
        {
            isRunning = false;
        }
        else if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_RIGHT)
            {
                PlayerRect.x += TILE_SIZE;
                PlayerRect.x = PlayerRect.x % SCREEN_WIDTH;
                if (checkWall(PlayerRect.x, PlayerRect.y))
                {
                    PlayerRect.x -= TILE_SIZE;
                    PlayerRect.x += SCREEN_WIDTH;
                    PlayerRect.x = PlayerRect.x % SCREEN_WIDTH;
                }
                direction = 3;
                toggle = !toggle;
            }
            else if (event.key.keysym.sym == SDLK_LEFT)
            {
                PlayerRect.x -= TILE_SIZE;
                PlayerRect.x += SCREEN_WIDTH;
                PlayerRect.x = PlayerRect.x % SCREEN_WIDTH;
                if (checkWall(PlayerRect.x, PlayerRect.y))
                {
                    PlayerRect.x += TILE_SIZE;
                    PlayerRect.x = PlayerRect.x % SCREEN_WIDTH;
                }
                direction = 2;
                toggle = !toggle;
            }
            else if (event.key.keysym.sym == SDLK_DOWN)
            {
                PlayerRect.y += TILE_SIZE;
                PlayerRect.y = PlayerRect.y % SCREEN_HEIGHT;
                if (checkWall(PlayerRect.x, PlayerRect.y))
                {
                    PlayerRect.y -= TILE_SIZE;
                    PlayerRect.y += SCREEN_HEIGHT;
                    PlayerRect.y = PlayerRect.y % SCREEN_HEIGHT;
                }
                direction = 1;
                toggle = !toggle;
            }
            else if (event.key.keysym.sym == SDLK_UP)
            {
                PlayerRect.y -= TILE_SIZE;
                PlayerRect.y += SCREEN_HEIGHT;
                PlayerRect.y = PlayerRect.y % SCREEN_HEIGHT;
                if (checkWall(PlayerRect.x, PlayerRect.y))
                {
                    PlayerRect.y += TILE_SIZE;
                    PlayerRect.y = PlayerRect.y % SCREEN_HEIGHT;
                }
                direction = 0;
                toggle = !toggle;
            }
        }
    }
}