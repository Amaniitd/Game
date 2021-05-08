#include "Texture.hpp"
#include "Object.hpp"

void Object::initObject(const char *filename, int x, int y)
{
    objTexture = texture::loadTexture(filename);
    xpos = x;
    ypos = y;
    dstRect.x = x;
    dstRect.y = y;
    dstRect.w = 32;
    dstRect.h = 32;
}

void Object::setSource(int x, int y, int w, int h)
{
    srcRect.h = h;
    srcRect.w = w;
    srcRect.x = x;
    srcRect.y = y;
}
void Object::setSource(int x, int y)
{
    srcRect.x = x;
    srcRect.y = y;
}
void Object::setDest(int x, int y, int w, int h)
{
    dstRect.x = x;
    dstRect.y = y;
    dstRect.w = w;
    dstRect.h = h;
}
void Object::setDest(int x, int y)
{
    dstRect.x = x;
    dstRect.y = y;
}
void Object::Render()
{
    tmpRect = dstRect;
    tmpRect.y -= 24;
    tmpRect.x -= 8;
    tmpRect.w = 48;
    tmpRect.h = 48;
    cout << dstRect.x << " " << dstRect.y << endl;
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &tmpRect);
}