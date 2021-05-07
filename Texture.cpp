#include "Texture.hpp"

SDL_Texture *texture::loadTexture(const char *filename)
{
    SDL_Surface *tmpSurface = IMG_Load(filename);
    if (tmpSurface == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", filename, SDL_GetError());
        exit(1);
    }
    SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return tex;
}

void texture::Draw(SDL_Texture *tex, SDL_Rect dst)
{
    SDL_RenderCopy(Game::renderer, tex, NULL, &dst);
}

void texture::Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dst)
{
    SDL_RenderCopy(Game::renderer, tex, &src, &dst);
}