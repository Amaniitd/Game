#pragma once

#include <vector>
#include "Object.hpp"

class Entity : public Object
{
public:
    void setHealth(int h) { health = h; }
    void setMaxHealth(int h) { maxHealth = h; }
    int getHealth() { return health; }
    int getMaxHealth() { return maxHealth; }
    int createCycle(int row, int w, int h, int amount, int speed);
    void setCurrentAnimation(int c)
    {
        begin = 0;
        currAnimation = c;
    }
    void updateAnimation();

private:
    int health, maxHealth;
    struct cycle
    {
        int row;
        int w;
        int h;
        int amount;
        int speed;
        int tick;
    };
    int currAnimation;
    int begin;
    vector<cycle> animations;
};