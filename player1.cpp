#include "player1.hpp"

void player1::handleEvents()
{

    while (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_RIGHT)
            {

            }
            else if (event.key.keysym.sym == SDLK_LEFT)
            {

            }
            else if (event.key.keysym.sym == SDLK_DOWN)
            {

            }
            else if (event.key.keysym.sym == SDLK_UP)
            {
                
            }
        }
    }
}
