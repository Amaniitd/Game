#pragma once
#include "Game.hpp"
#include "SDL2/SDL_ttf.h"
TTF_Font *Sans;
void initTextLoader(int size)
{
    TTF_Init();
    Sans = TTF_OpenFont("Fonts/FreeSans.ttf", size);
    if (Sans == NULL)
    {
        fprintf(stderr, "error: font not found\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

void displayText(const char *text, int x, int y, SDL_Color Color)
{
    if (Sans == NULL)
    {
        fprintf(stderr, "error: font not found\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_Surface *surfaceMessage = TTF_RenderText_Solid(Sans, text, Color);

    SDL_Texture *Message = SDL_CreateTextureFromSurface(Game::renderer, surfaceMessage);
    SDL_Rect Message_rect;
    Message_rect.x = x;
    Message_rect.y = y;
    Message_rect.w = surfaceMessage->w;
    Message_rect.h = surfaceMessage->h;
    SDL_RenderCopy(Game::renderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
    TTF_CloseFont(Sans);
}