#include "Game.hpp"
#include "Texture.hpp"
#include "Map.hpp"

Map *map;

Game::Game()
{
    // PlayerRect.x = TILE_SIZE;
    // PlayerRect.y = TILE_SIZE;
    // PlayerRect.w = TILE_SIZE;
    // PlayerRect.h = TILE_SIZE;
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
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer)
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    }
    map = new Map();
    return 1;
}

bool Game::createMap()
{
    return true;
}
bool Game::loadTiles()
{
    return map->loadMap();
}

void Game::createMapSurface()
{
    map->drawMap();
    SDL_RenderPresent(renderer);
}

bool Game::checkWall(int x, int y)
{
    return map->map[(y / TILE_SIZE)][x / TILE_SIZE];
}

void Game::Cleanup()
{
    //Destroy window
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();
    cout << "Game cleaned" << endl;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    map->drawMap();
    // SDL_Texture *tempTex;
    // if (toggle)
    // {
    //     tempTex = texture::loadTexture("image/player2.bmp", renderer);
    // }
    // else
    // {
    //     tempTex = texture::loadTexture("image/player1x.bmp", renderer);
    // }
    // SDL_RenderCopy(renderer, tempTex, NULL, &PlayerRect);
    SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{

    while (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_QUIT)
        {
            isRunning = false;
        }
        // else if (event.type == SDL_KEYDOWN)
        // {
        //     if (event.key.keysym.sym == SDLK_RIGHT)
        //     {
        //         PlayerRect.x += TILE_SIZE;
        //         PlayerRect.x = PlayerRect.x % SCREEN_WIDTH;
        //         if (checkWall(PlayerRect.x, PlayerRect.y))
        //         {
        //             PlayerRect.x -= TILE_SIZE;
        //             PlayerRect.x += SCREEN_WIDTH;
        //             PlayerRect.x = PlayerRect.x % SCREEN_WIDTH;
        //         }
        //         direction = 3;
        //         toggle = !toggle;
        //     }
        //     else if (event.key.keysym.sym == SDLK_LEFT)
        //     {
        //         PlayerRect.x -= TILE_SIZE;
        //         PlayerRect.x += SCREEN_WIDTH;
        //         PlayerRect.x = PlayerRect.x % SCREEN_WIDTH;
        //         if (checkWall(PlayerRect.x, PlayerRect.y))
        //         {
        //             PlayerRect.x += TILE_SIZE;
        //             PlayerRect.x = PlayerRect.x % SCREEN_WIDTH;
        //         }
        //         direction = 2;
        //         toggle = !toggle;
        //     }
        //     else if (event.key.keysym.sym == SDLK_DOWN)
        //     {
        //         PlayerRect.y += TILE_SIZE;
        //         PlayerRect.y = PlayerRect.y % SCREEN_HEIGHT;
        //         if (checkWall(PlayerRect.x, PlayerRect.y))
        //         {
        //             PlayerRect.y -= TILE_SIZE;
        //             PlayerRect.y += SCREEN_HEIGHT;
        //             PlayerRect.y = PlayerRect.y % SCREEN_HEIGHT;
        //         }
        //         direction = 1;
        //         toggle = !toggle;
        //     }
        //     else if (event.key.keysym.sym == SDLK_UP)
        //     {
        //         PlayerRect.y -= TILE_SIZE;
        //         PlayerRect.y += SCREEN_HEIGHT;
        //         PlayerRect.y = PlayerRect.y % SCREEN_HEIGHT;
        //         if (checkWall(PlayerRect.x, PlayerRect.y))
        //         {
        //             PlayerRect.y += TILE_SIZE;
        //             PlayerRect.y = PlayerRect.y % SCREEN_HEIGHT;
        //         }
        //         direction = 0;
        //         toggle = !toggle;
        //     }
        // }
    }
}