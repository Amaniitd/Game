#include "botAI.hpp"
void botAI::move()
{
    if (m1 == 0)
    {
        l = false;
        rr = false;
        u = false;
        d = false;
        int nextR = Rtraces[botRow][botCol];
        int nextC = Ctraces[botRow][botCol];
        if (nextR > botRow)
        {
            d = true;
        }
        else if (nextR < botRow)
        {
            u = true;
        }
        else if (nextC > botCol)
        {
            rr = true;
        }
        else
        {
            l = true;
        }
        botRow = nextR;
        botCol = nextC;
    }
    if (l)
    {
        if (getCurAnimation() != botRunl)
        {
            setCurAnimation(botRunl);
        }
        setDest(getDX() - 2, getDY());
    }
    else if (rr)
    {
        if (getCurAnimation() != botRunr)
        {
            setCurAnimation(botRunr);
        }
        setDest(getDX() + 2, getDY());
    }
    else if (u)
    {
        if (getCurAnimation() != botRunu)
        {
            setCurAnimation(botRunu);
        }
        setDest(getDX(), getDY() - 2);
    }
    else if (d)
    {
        if (getCurAnimation() != botRunl)
        {
            setCurAnimation(botRunl);
        }
        setDest(getDX(), getDY() + 2);
    }
    m1 += 2;
    if (m1 == 32)
        m1 = 0;
}
void botAI::updatePath()
{
}
void botAI::initializeBot(int map[Game::MAP_HEIGHT][Game::MAP_WIDTH])
{
    m1 = 0;
    m2 = 0;
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
    botRow = xpos;
    botCol = ypos;
    botRunr = createCycle(12, 64, 64, 9, 10);
    botRund = createCycle(11, 64, 64, 9, 10);
    botRunl = createCycle(10, 64, 64, 9, 10);
    botRunu = createCycle(9, 64, 64, 9, 10);
    setCurAnimation(botRunr);
    initObject("image/bots.png", ypos * 32, xpos * 32);
}

void botAI::solve(int sr, int sc, int map[Game::MAP_HEIGHT][Game::MAP_WIDTH])
{

    if (m1 == 0)
    {
        for (int i = 0; i < Game::MAP_HEIGHT; i++)
        {
            for (int j = 0; j < Game::MAP_WIDTH; j++)
            {
                visited[i][j] = 0;
            }
        }
        rq = queue<int>();
        cq = queue<int>();
        rq.push(sr);
        cq.push(sc);
        visited[sr][sc] = true;
        count = 0;
        reached_end = false;
        node_left_in_layer = 1;
        nodes_in_next_layer = 0;
        while (!rq.empty())
        {
            r = rq.front();
            c = cq.front();
            rq.pop();
            cq.pop();
            if (r == botRow && c == botCol)
            {
                reached_end = true;
                break;
            }
            explore_neighbours(r, c, map);
            node_left_in_layer--;
            if (node_left_in_layer == 0)
            {
                node_left_in_layer = nodes_in_next_layer;
                nodes_in_next_layer = 0;
                count++;
            }
        }
    }
    if (count > 0)
        move();
}

void botAI::explore_neighbours(int r, int c, int map[Game::MAP_HEIGHT][Game::MAP_WIDTH])
{
    for (int i = 0; i < 4; i++)
    {
        int rr = r + dr[i];
        int cc = c + dc[i];
        if (rr < 0 or cc < 0)
            continue;
        if (rr >= Game::MAP_HEIGHT or cc >= Game::MAP_WIDTH)
            continue;
        if (map[rr][cc])
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
