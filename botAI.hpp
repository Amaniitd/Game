#pragma once
#include "Game.hpp"
#include "Entity.hpp"
#include <queue>
class botAI : public Entity
{
public:
    void move();
    bool alive;
    void solve(int sr, int sc, int map[Game::MAP_HEIGHT][Game::MAP_WIDTH]);
    void updatePath();
    void initializeBot(int map[Game::MAP_HEIGHT][Game::MAP_WIDTH]);
    bool reached;
    int Rtraces[Game::MAP_HEIGHT][Game::MAP_WIDTH];
    int Ctraces[Game::MAP_HEIGHT][Game::MAP_WIDTH];
    void explore_neighbours(int r, int c, int map[Game::MAP_HEIGHT][Game::MAP_WIDTH]);
    void triggerDeath();
    bool dieing;
    int node_left_in_layer;
    int nodes_in_next_layer;
    int botRunr;
    int botRund;
    int botRunl;
    int botRunu;
    int botAttackl;
    int botAttackr;
    int botAttacku;
    int botAttackd;
    int botDie;
    int r, c;
    int m1, m2;
    int count;
    bool l, rr, u, d;
    queue<int> rq, cq;
    int visited[Game::MAP_HEIGHT][Game::MAP_WIDTH];
    bool reached_end = false;
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};
    int botRow, botCol;
};