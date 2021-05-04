#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 640;

//The window we'll be rendering to
SDL_Window *window = NULL;

//The surface contained by the window
SDL_Surface *screenSurface = NULL;

SDL_Surface *walls;

int tiles[600];

void printTile(int *tiles)
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            cout << tiles[30 * i + j] << " ";
        }
        cout << endl;
    }
}

SDL_Surface *createMapSurface(int *tiles)
{
    SDL_Surface *surf = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0, 0, 0, 0);
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
            if (currentTile == 0)
            {
                color = SDL_MapRGB(surf->format, 0, 0, 0);
            }
            else if (currentTile == 1)
            {
                color = SDL_MapRGB(surf->format, 255, 255, 255);
            }
            SDL_FillRect(surf, &rectWall, color);
            column++;
        }
        column = 0;
        row++;
    }
    if (surf == NULL)
    {
        SDL_Log("SDL_CreateRGBSurface() failed: %s", SDL_GetError());
        exit(1);
    }
    return surf;
}

bool loadTiles()
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

bool checkWall(int *lists, int x, int y)
{
    return lists[(y / 32) * (SCREEN_WIDTH / 32) + x / 32];
}

bool userAction(int *tiles)
{
}

bool initialize()
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
    //Get window surface
    screenSurface = SDL_GetWindowSurface(window);

    return 1;
}

bool createMap()
{
    return true;
}

int main(int argc, char *args[])
{
    cout << "Initializing..." << endl;
    if (!initialize())
    {
        cout << "Failed to Initialize..." << endl;
        return 0;
    }
    cout << "Successfully initialized!!" << endl;
    cout << "Creating a map..." << endl;
    if (!createMap())
    {
        cout << "Faild to create a map" << endl;
        return 0;
    }
    cout << "Map created successfully!!" << endl;
    cout << "Loading the map..." << endl;
    if (!loadTiles())
    {
        cout << "Failed to load the map" << endl;
        return 0;
    }
    cout << "Map loaded successfully!!" << endl;

    walls = createMapSurface(tiles);
    //Fill the surface white

    SDL_Event event;
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 32;
    rect.h = 32;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    rect.x += 32;
                    rect.x = rect.x % SCREEN_WIDTH;
                    if (checkWall(tiles, rect.x, rect.y))
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
                    if (checkWall(tiles, rect.x, rect.y))
                    {
                        rect.x += 32;
                        rect.x = rect.x % SCREEN_WIDTH;
                    }
                }
                else if (event.key.keysym.sym == SDLK_DOWN)
                {
                    rect.y += 32;
                    rect.y = rect.y % SCREEN_HEIGHT;
                    if (checkWall(tiles, rect.x, rect.y))
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
                    if (checkWall(tiles, rect.x, rect.y))
                    {
                        rect.y += 32;
                        rect.y = rect.y % SCREEN_HEIGHT;
                    }
                }
            }
        }
        // SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 3, 252, 127));
        SDL_BlitSurface(walls, NULL, screenSurface, NULL);
        SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 161, 66, 245));
        SDL_UpdateWindowSurface(window);
    }
    SDL_FreeSurface(walls);
    //Destroy window
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}