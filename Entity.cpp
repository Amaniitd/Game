#include "Entity.hpp"

int Entity::createCycle(int row, int w, int h, int amount, int speed)
{
    cycle tmp;
    tmp.row = row - 1;
    tmp.w = w;
    tmp.h = h;
    tmp.amount = amount;
    tmp.speed = speed;
    tmp.tick = 0;
    animations.push_back(tmp);
    return animations.size() - 1;
}

void Entity::updateAnimation()
{
    setSource(animations[currAnimation].w * animations[currAnimation].tick,
              animations[currAnimation].h * animations[currAnimation].row,
              animations[currAnimation].w,
              animations[currAnimation].h);
    if (begin > animations[currAnimation].speed)
    {
        animations[currAnimation].tick++;
        begin = 0;
    }
    begin++;
    if (animations[currAnimation].tick >= animations[currAnimation].amount)
    {
        animations[currAnimation].tick = 0;
    }
}