#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include "Game.hpp"

using namespace std;

void displayScore()
{
}

int main(int argc, char *args[])
{
    cout << "Initializing..." << endl;
    Game *game = new Game();
    if (!game->initialize())
    {
        cout << "Failed to Initialize..." << endl;
        return 0;
    }
    cout << "Successfully initialized!!" << endl;

    cout << "Creating a map..." << endl;
    if (!game->createMap())
    {
        cout << "Faild to create a map" << endl;
        return 0;
    }
    cout << "Map created successfully!!" << endl;

    cout << "Loading the map..." << endl;
    if (!game->loadTiles())
    {
        cout << "Failed to load the map" << endl;
        return 0;
    }
    cout << "Map loaded successfully!!" << endl;

    cout << "Displaying the map..." << endl;
    game->createMapSurface();
    cout << "Map displayed successfully!!" << endl;

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;
    if (game->running())
    {
        cout << "Game is now running!" << endl;
        cout << "...//...WELCOME!!...//..." << endl;
    }
    while (game->running())
    {
        frameStart = SDL_GetTicks();
        game->handleEvents();
        game->render();
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    cout << "Game finished!!" << endl;
    cout << "********************************" << endl
         << endl;
    cout << "-------------Result---------------" << endl;
    cout << endl
         << "********************************" << endl;
    displayScore();
    cout << "Cleaning the game..." << endl;
    game->Cleanup();

    return 0;
}