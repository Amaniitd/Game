
#include "Audio.hpp"
#include "Game.hpp"

Audio::~Audio()
{
    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
}

void Audio::load(const char *filename)
{
    SDL_LoadWAV(filename, &wavSpec, &wavBuffer, &wavLength);
    if (&wavBuffer == NULL)
    {
        std::cout << "audio not found" << std::endl;
    }
    deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
}

void Audio::play()
{
    SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0);
}
void Audio::pause()
{
    SDL_CloseAudioDevice(deviceId);
}
