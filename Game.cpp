#include "Game.hpp"
#include "Texture.hpp"
#include "Map.hpp"
#include "Object.hpp"
#include "textLoader.hpp"
#include "welcomeScreen.hpp"
#include "Entity.hpp"

Map *map;

Entity player;

Game::Game()
{
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
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
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
    map = new Map();
    player.initObject("image/female.png", 32, 32);
    idolr = player.createCycle(12, 64, 64, 2, 30);
    idold = player.createCycle(11, 64, 64, 2, 30);
    idoll = player.createCycle(10, 64, 64, 2, 30);
    idolu = player.createCycle(9, 64, 64, 9, 30);
    runr = player.createCycle(12, 64, 64, 9, 2);
    rund = player.createCycle(11, 64, 64, 9, 2);
    runl = player.createCycle(10, 64, 64, 9, 2);
    runu = player.createCycle(9, 64, 64, 9, 2);
    player.setCurAnimation(idolr);
    speed = 3;
    initTextLoader(100);
    initWelcomeScreen();
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
    // intro.load("sound/intermission.wav");
    // intro.play();
    // loadScreen();
    // SDL_RenderPresent(renderer);
    // SDL_Delay(500);
    // SDL_Color color = {237, 52, 52, 0};
    // displayText("Hunter X Hunter", 150, 400, color);
    // SDL_RenderPresent(renderer);
    // SDL_Delay(2000);
    // map->drawMapWithDelay();
    // intro.pause();
    // SDL_RenderPresent(renderer);
}

bool Game::checkWall(int x, int y)
{
    if (x % TILE_SIZE < 10 && y % TILE_SIZE < 10)
    {
        return map->map[y / TILE_SIZE][x / TILE_SIZE];
    }
    if (x % TILE_SIZE < 10)
    {
        return map->map[y / TILE_SIZE][(x / TILE_SIZE)] || map->map[(y + 24) / TILE_SIZE][(x / TILE_SIZE)];
    }
    if (y % TILE_SIZE < 10)
    {
        return map->map[y / TILE_SIZE][(x / TILE_SIZE)] || map->map[(y / TILE_SIZE)][(x + 24) / TILE_SIZE];
    }

    return map->map[y / TILE_SIZE][(x / TILE_SIZE)] || map->map[(y / TILE_SIZE)][(x + 24) / TILE_SIZE] || map->map[(y + 24) / TILE_SIZE][(x + 24) / TILE_SIZE] || map->map[((y + 24) / TILE_SIZE)][(x / TILE_SIZE)];
}
void Game::Cleanup()
{
    //Destroy window
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    //Quit SDL subsystems
    SDL_Quit();
    cout << "Game cleaned" << endl;
}

void Game::update()
{
    if (l)
    {
        if (player.getCurAnimation() != runl)
        {
            player.setCurAnimation(runl);
        }
        player.setDest(player.getDX() - speed, player.getDY());
        if (checkWall(player.getDX(), player.getDY()))
        {
            player.setDest(player.getDX() + speed, player.getDY());
        }
    }
    if (r)
    {
        if (player.getCurAnimation() != runr)
        {
            player.setCurAnimation(runr);
        }
        player.setDest(player.getDX() + speed, player.getDY());
        if (checkWall(player.getDX(), player.getDY()))
        {
            player.setDest(player.getDX() - speed, player.getDY());
        }
    }
    if (u)
    {
        if (player.getCurAnimation() != runu)
        {
            player.setCurAnimation(runu);
        }
        player.setDest(player.getDX(), player.getDY() - speed);
        if (checkWall(player.getDX(), player.getDY()))
        {
            player.setDest(player.getDX(), player.getDY() + speed);
        }
    }
    if (d)
    {
        if (player.getCurAnimation() != rund)
        {
            player.setCurAnimation(rund);
        }

        player.setDest(player.getDX(), player.getDY() + speed);
        if (checkWall(player.getDX(), player.getDY()))
        {
            player.setDest(player.getDX(), player.getDY() - speed);
        }
    }
    player.updateAnimation();
}
void Game::render()
{
    SDL_RenderClear(renderer);
    map->drawMap();
    player.Render();
    // player2.Render();
    // player3.Render();
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
        else if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_ESCAPE)
                isRunning = false;
            if (event.key.keysym.sym == SDLK_a)
            {
                l = 1;
                r = 0;
            }
            if (event.key.keysym.sym == SDLK_d)
            {
                r = 1;
                l = 0;
            }
            if (event.key.keysym.sym == SDLK_w)
            {
                u = 1;
                d = 0;
            }
            if (event.key.keysym.sym == SDLK_s)
            {
                d = 1;
                u = 0;
            }
        }
        if (event.type == SDL_KEYUP)
        {
            if (event.key.keysym.sym == SDLK_a)
            {
                l = 0;
                player.setCurAnimation(idoll);
            }
            if (event.key.keysym.sym == SDLK_d)
            {
                r = 0;
                player.setCurAnimation(idolr);
            }
            if (event.key.keysym.sym == SDLK_w)
            {
                u = 0;
                player.setCurAnimation(idolu);
            }
            if (event.key.keysym.sym == SDLK_s)
            {
                d = 0;
                player.setCurAnimation(idold);
            }
        }
    }
}
