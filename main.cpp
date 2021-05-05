#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include "Game.hpp"

using namespace std;

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 640;


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

    game->createMapSurface();
    while (game->isRunning)
    {
        game->handleEvents();
        game->render();
    }

    game->Cleanup();

    return 0;
}