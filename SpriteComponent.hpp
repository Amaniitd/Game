#pragma once

#include "Components.hpp"
#include "SDL2/SDL.h"

class SpriteComponent : public Component
{
private:
    TransitionComponent *position;
    SDL_Texture *texture;
    SDL_Rect srcRect, dstRect;

public:
    SpriteComponent() = default;
    SpriteComponent(const char *path)
    {
        texture = texture::loadTexture(path);
    }
    void init() override
    {
        position = &entity->getComponent<TransitionComponent>();
        srcRect.x = srcRect.y = 0;
        srcRect.w = 64;
        srcRect.h = 64;
        dstRect.w = dstRect.h = 32;
    }
    void update() override
    {
        dstRect.x = position->x();
        dstRect.y = position->y();
    }
    void draw() override
    {
    }
};