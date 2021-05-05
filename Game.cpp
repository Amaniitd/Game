#include "Game.hpp"
#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

Game::Game()
{
    rect.x = 0;
    rect.y = 0;
    rect.w = 32;
    rect.h = 32;
    isRunning = true;
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
    walls = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0, 0, 0, 0);
    int row = 0;
    int column = 0;
    SDL_Rect rectWall;
    rectWall.w = 32;
    rectWall.h = 32;

    while (row < SCREEN_HEIGHT / 32)
    {
        while (column < SCREEN_WIDTH / 32)
        {
            rectWall.x = column * 32;
            rectWall.y = row * 32;
            int currentTile = tiles[row * 30 + column];
            Uint32 color;
            if (currentTile == 1)
            {
                color = SDL_MapRGB(walls->format, 25, 255, 55);
                SDL_FillRect(walls, &rectWall, color);
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
    return tiles[(y / 32) * (SCREEN_WIDTH / 32) + x / 32];
}

void Game::Cleanup()
{
    //Destroy window
    SDL_DestroyWindow(window);
    SDL_FreeSurface(walls);

    //Quit SDL subsystems
    SDL_Quit();
}

void Game::render()
{
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 3, 252, 127));
    SDL_BlitSurface(walls, NULL, screenSurface, NULL);
    SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 161, 66, 245));
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
                rect.x += 32;
                rect.x = rect.x % SCREEN_WIDTH;
                if (checkWall(rect.x, rect.y))
                {
                    rect.x -= 32;
                    rect.x += SCREEN_WIDTH;
                    rect.x = rect.x % SCREEN_WIDTH;
                }
            }
            else if (event.key.keysym.sym == SDLK_LEFT)
            {
                rect.x -= 32;
                rect.x += SCREEN_WIDTH;
                rect.x = rect.x % SCREEN_WIDTH;
                if (checkWall(rect.x, rect.y))
                {
                    rect.x += 32;
                    rect.x = rect.x % SCREEN_WIDTH;
                }
            }
            else if (event.key.keysym.sym == SDLK_DOWN)
            {
                rect.y += 32;
                rect.y = rect.y % SCREEN_HEIGHT;
                if (checkWall(rect.x, rect.y))
                {
                    rect.y -= 32;
                    rect.y += SCREEN_HEIGHT;
                    rect.y = rect.y % SCREEN_HEIGHT;
                }
            }
            else if (event.key.keysym.sym == SDLK_UP)
            {
                rect.y -= 32;
                rect.y += SCREEN_HEIGHT;
                rect.y = rect.y % SCREEN_HEIGHT;
                if (checkWall(rect.x, rect.y))
                {
                    rect.y += 32;
                    rect.y = rect.y % SCREEN_HEIGHT;
                }
            }
        }
    }
}