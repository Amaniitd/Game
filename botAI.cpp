#include "botAI.hpp"
void botAI::move()
{
}
void botAI::updatePath()
{
}
void botAI::initializeBot(int map[Game::MAP_HEIGHT][Game::MAP_WIDTH])
{
    int xpos = rand() % (Game::MAP_HEIGHT - 2);
    xpos++;
    int ypos = rand() % (Game::MAP_WIDTH - 2);
    ypos++;
    int i = 0;
    while (map[xpos][ypos])
    {
        if (!map[xpos + dr[i]][ypos + dc[i]])
        {
            xpos += dr[i];
            ypos += dc[i];
        }
        i++;
    }
    botRunr = createCycle(12, 64, 64, 9, 10);
    botRund = createCycle(11, 64, 64, 9, 10);
    botRunl = createCycle(10, 64, 64, 9, 10);
    botRunu = createCycle(9, 64, 64, 9, 10);
    setCurAnimation(botRunr);
    initObject("image/bots.png", ypos * 32, xpos * 32);
}

void botAI::solve()
{
    rq.push(sr);
    cq.push(sc);
    visited[sr][sc] = true;
    r = rq.front();
    c = cq.front();
    rq.pop();
    cq.pop();
    if (reached)
    {
        reached_end = true;
        return;
    }
    explore_neighbours(r, c);
    node_left_in_layer--;
    if (node_left_in_layer == 0)
    {
        node_left_in_layer = nodes_in_next_layer;
        nodes_in_next_layer = 0;
    }
}

void botAI::explore_neighbours(int r, int c)
{
    for (int i = 0; i < 4; i++)
    {
        int rr = r + dr[i];
        int cc = c + dc[i];
        if (rr < 0 or cc < 0)
            continue;
        if (rr >= Game::MAP_HEIGHT or cc >= Game::MAP_HEIGHT)
            continue;
        if (visited[rr][cc])
            continue;
        Rtraces[rr][cc] = r;
        Ctraces[rr][cc] = c;
        rq.push(rr);
        cq.push(cc);
        visited[rr][cc] = true;
        nodes_in_next_layer++;
    }
}
