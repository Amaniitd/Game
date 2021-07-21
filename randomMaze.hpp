#pragma once
#include <vector>
#include "Game.hpp"
vector<pair<int, int>> edge;
class subSet
{
public:
    int parent;
    int size;
};

subSet subsets[Game::MAP_WIDTH * Game::MAP_HEIGHT];

int find(int a)
{
    if (subsets[a].parent != a)
        subsets[a].parent = find(subsets[a].parent);
    return subsets[a].parent;
}

void Union(int x, int y, int map[Game::MAP_HEIGHT][Game::MAP_WIDTH])
{
    int a = find(x);
    int b = find(y);
    if (a == b)
        return;
    if (subsets[a].size < subsets[b].size)
    {
        subsets[a].parent = b;
        subsets[b].size += subsets[a].size;
    }
    else
    {
        subsets[b].parent = a;
        subsets[a].size += subsets[b].size;
    }

    int v = (x + y) / 2;
    int c = v % Game::MAP_WIDTH;
    int r = v / Game::MAP_WIDTH;
    map[r][c] = 0;
}

void randomST(int map[Game::MAP_HEIGHT][Game::MAP_WIDTH])
{
    for (int i = 1; i < Game::MAP_HEIGHT; i += 2)
        for (int j = 1; j < Game::MAP_WIDTH; j += 2)
            map[i][j] = 0;
    for (int i = 1; i < Game::MAP_HEIGHT; i += 2)
    {
        for (int j = 1; j < Game::MAP_WIDTH; j += 2)
        {
            int cur = Game::MAP_WIDTH * i + j;

            subsets[cur].size = 1;
            subsets[cur].parent = cur;
            if (j > 1)
                edge.push_back({cur - 2, cur});
            if (j < Game::MAP_WIDTH - 2)
                edge.push_back({cur, cur + 2});
            if (i > 1)
                edge.push_back({cur - 2 * Game::MAP_WIDTH, cur});
            if (i < Game::MAP_HEIGHT - 2)
                edge.push_back({cur, cur + 2 * Game::MAP_WIDTH});
        }
    }
    srand(time(0));
    while (!edge.empty())
    {
        int s = edge.size();
        int index = rand() % s;
        Union(edge[index].first, edge[index].second, map);
        vector<pair<int, int>> edge1;
        for (int i = 0; i < s; ++i)
        {
            if (i == index)
                continue;
            edge1.push_back(edge[i]);
        }
        edge = edge1;
    }
}

bool Maze(int map[Game::MAP_HEIGHT][Game::MAP_WIDTH])
{
    for (int i = 0; i < Game::MAP_HEIGHT; i++)
    {
        for (int j = 0; j < Game::MAP_WIDTH; j++)
        {
            map[i][j] = 1;
        }
    }
    randomST(map);
    for (int i = 0; i < Game::MAP_WIDTH; i++)
    {
        map[0][i] = 1;
        map[Game::MAP_HEIGHT - 1][i] = 1;
    }
    for (int i = 0; i < Game::MAP_HEIGHT; i++)
    {
        map[i][Game::MAP_WIDTH - 1] = 1;
        map[i][0] = 1;
    }
    return true;
}
