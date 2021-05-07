#include "Game.hpp"
#include "Texture.hpp"
#include "Map.hpp"
#include "Object.hpp"
#include "textLoader.hpp"
#include "welcomeScreen.hpp"
#include "Entity.hpp"
// #include "Components.hpp"

Map *map;

Entity player1;

// Manager manager;
// auto &newPlayer(manager.addEntity());

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
    if (renderer)
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    }
    map = new Map();
    player1.initObject("image/female.png", 32, 32);
    attack = player1.createCycle(20, 64, 64, 13, 10);
    player1.setCurrentAnimation(attack);
    initTextLoader(100);
    initWelcomeScreen();

    // newPlayer.addComponent<TransitionComponent>();
    // newPlayer.addComponent<SpriteComponent>("image/female.png");
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
    return map->map[(y / TILE_SIZE)][x / TILE_SIZE];
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
    player1.updateAnimation();
    // manager.refresh();
    // manager.update();
    // cout << newPlayer.getComponent<TransitionComponent>().x() << " " << newPlayer.getComponent<TransitionComponent>().y() << endl;
}
void Game::render()
{
    SDL_RenderClear(renderer);
    map->drawMap();
    player1.Render();
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
            if (event.key.keysym.sym == SDLK_RIGHT)
            {
                // PlayerRect.x += TILE_SIZE;
                // PlayerRect.x = PlayerRect.x % SCREEN_WIDTH;
                // if (checkWall(PlayerRect.x, PlayerRect.y))
                // {
                //     PlayerRect.x -= TILE_SIZE;
                //     PlayerRect.x += SCREEN_WIDTH;
                //     PlayerRect.x = PlayerRect.x % SCREEN_WIDTH;
                // }
                // direction = 3;
                // toggle = !toggle;
            }
            else if (event.key.keysym.sym == SDLK_LEFT)
            {
                // PlayerRect.x -= TILE_SIZE;
                // PlayerRect.x += SCREEN_WIDTH;
                // PlayerRect.x = PlayerRect.x % SCREEN_WIDTH;
                // if (checkWall(PlayerRect.x, PlayerRect.y))
                // {
                //     PlayerRect.x += TILE_SIZE;
                //     PlayerRect.x = PlayerRect.x % SCREEN_WIDTH;
                // }
                // direction = 2;
                // toggle = !toggle;
            }
            else if (event.key.keysym.sym == SDLK_DOWN)
            {
                // PlayerRect.y += TILE_SIZE;
                // PlayerRect.y = PlayerRect.y % SCREEN_HEIGHT;
                // if (checkWall(PlayerRect.x, PlayerRect.y))
                // {
                //     PlayerRect.y -= TILE_SIZE;
                //     PlayerRect.y += SCREEN_HEIGHT;
                //     PlayerRect.y = PlayerRect.y % SCREEN_HEIGHT;
                // }
                // direction = 1;
                // toggle = !toggle;
            }
            else if (event.key.keysym.sym == SDLK_UP)
            {
                // PlayerRect.y -= TILE_SIZE;
                // PlayerRect.y += SCREEN_HEIGHT;
                // PlayerRect.y = PlayerRect.y % SCREEN_HEIGHT;
                // if (checkWall(PlayerRect.x, PlayerRect.y))
                // {
                //     PlayerRect.y += TILE_SIZE;
                //     PlayerRect.y = PlayerRect.y % SCREEN_HEIGHT;
                // }
                // direction = 0;
                // toggle = !toggle;
            }
        }
    }
}
