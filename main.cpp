#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 640;

int main(int argc, char *args[])
{
    //The window we'll be rendering to
    SDL_Window *window = NULL;

    //The surface contained by the window
    SDL_Surface *screenSurface = NULL;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        //Create window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface(window);

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
                            rect.x = rect.x + 32;
                            rect.x = rect.x % SCREEN_WIDTH;
                        }
                        else if (event.key.keysym.sym == SDLK_LEFT)
                        {
                            rect.x = rect.x - 32;
                            rect.x = (SCREEN_WIDTH + rect.x) % SCREEN_WIDTH;
                        }
                        else if (event.key.keysym.sym == SDLK_DOWN)
                        {
                            rect.y = rect.y + 32;
                            rect.y = rect.y % SCREEN_HEIGHT;
                        }
                        else if (event.key.keysym.sym == SDLK_UP)
                        {
                            rect.y = rect.y - 32;
                            rect.y = (SCREEN_HEIGHT + rect.y) % SCREEN_HEIGHT;
                        }
                    }
                }
                SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 3, 252, 127));
                SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 161, 66, 245));
                SDL_UpdateWindowSurface(window);
            }

            //Update the surface
            SDL_UpdateWindowSurface(window);

            //Wait two seconds
        }
    }
    //Destroy window
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}