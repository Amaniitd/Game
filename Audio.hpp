#pragma once
#include <SDL2/SDL.h>

class Audio
{
public:
    ~Audio();
    void load(const char *filename);
    void play();
    void pause();
    int length();

private:
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 *wavBuffer;
    SDL_AudioDeviceID deviceId;
};
