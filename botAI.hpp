#pragma once

#include "Entity.hpp"

class botAI : public Entity
{
public:
    void move();
    void updatePath();
    void initializeBot();
};