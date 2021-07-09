#include <vector>
#include <queue>
using namespace std;
#include "Map.hpp"
vector<pair<int, int>> edge;
const static int MAP_WIDTH = 35;
const static int MAP_HEIGHT = 25;
const static int TILE_SIZE = 32;
int map[MAP_HEIGHT][MAP_WIDTH];

class subSet
{
public:
    int parent;
    int size;
};

subSet subsets[MAP_WIDTH * MAP_HEIGHT];

int find(int a)
{
    if (subsets[a].parent != a)
        subsets[a].parent = find(subsets[a].parent);
    return subsets[a].parent;
}

void Union(int x, int y)
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
    int c = v % MAP_WIDTH;
    int r = v / MAP_WIDTH;
    map[r][c] = 0;
}

void randomST()
{
    for (int i = 1; i < MAP_HEIGHT; i += 2)
        for (int j = 1; j < MAP_WIDTH; j += 2)
            map[i][j] = 0;
    for (int i = 1; i < MAP_HEIGHT; i += 2)
    {
        for (int j = 1; j < MAP_WIDTH; j += 2)
        {
            int cur = MAP_WIDTH * i + j;

            subsets[cur].size = 1;
            subsets[cur].parent = cur;
            if (j > 1)
                edge.push_back({cur - 2, cur});
            if (j < MAP_WIDTH - 2)
                edge.push_back({cur, cur + 2});
            if (i > 1)
                edge.push_back({cur - 2 * MAP_WIDTH, cur});
            if (i < MAP_HEIGHT - 2)
                edge.push_back({cur, cur + 2 * MAP_WIDTH});
        }
    }
    srand(time(0));
    while (!edge.empty())
    {
        int s = edge.size();
        int index = rand() % s;
        Union(edge[index].first, edge[index].second);
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

bool Maze()
{
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            map[i][j] = 1;
        }
    }
    randomST();
    for (int i = 0; i < MAP_WIDTH; i++)
    {
        map[0][i] = 1;
        map[MAP_HEIGHT - 1][i] = 1;
    }
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        map[i][MAP_WIDTH - 1] = 1;
        map[i][0] = 1;
    }
    return true;
}
