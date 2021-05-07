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
    void setCurAnimation(int c)
    {
        begin = 0;
        currAnimation = c;
    }
    void updateAnimation();
    int getCurAnimation() const { return currAnimation; }

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
    int newAnim;
    vector<cycle> animations;
};