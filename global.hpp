#pragma once
const static int MAP_WIDTH = 35;
const static int MAP_HEIGHT = 25;
const static int TILE_SIZE = 32;
static int tiles[MAP_WIDTH * MAP_HEIGHT];
int map[MAP_HEIGHT][MAP_WIDTH];
const static int SCREEN_WIDTH = MAP_WIDTH * TILE_SIZE;
const static int SCREEN_HEIGHT = MAP_HEIGHT * TILE_SIZE;
#include "Game.hpp"
#include "Texture.hpp"
#include <SDL2/SDL_ttf.h>
#include "randomMaze.hpp"
#include "botAI.hpp"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>
#include "Texture.hpp"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
#include "Audio.hpp"
#include <vector>
#include <queue>
#include "Entity.hpp"
#include "Object.hpp"
#include "Map.hpp"
#include "textLoader.hpp"
#include "welcomeScreen.hpp"