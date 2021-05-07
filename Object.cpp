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

// void Object::Update()
// {
//     srcRect.h = 64;
//     srcRect.w = 64;
//     srcRect.x = 0;
//     srcRect.y = 0;

//     dstRect.x = xpos;
//     dstRect.y = ypos;
//     dstRect.w = 32;
//     dstRect.h = 32;
// }

void Object::setSource(int x, int y, int w, int h)
{
    cout << x << ", " << y << ", " << w << ", " << h << endl;
    srcRect.h = h;
    srcRect.w = w;
    srcRect.x = x;
    srcRect.y = y;
}
void Object::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &dstRect);
}