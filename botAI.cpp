#include "Game.hpp"
#include "botAI.hpp"
const static int MAP_WIDTH = 35;
const static int MAP_HEIGHT = 25;
void botAI::move()
{
}
void botAI::updatePath()
{
}
void botAI::initializeBot()
{
    int pos = rand() % 600;
    pos += 25;
    cout << pos << endl;
    int xpos = pos % 25;
    int ypos = pos / 25;
    cout << xpos << " " << ypos << endl;
    // while (map[ypos][xpos])
    // {
    //     int pos = rand() % (MAP_WIDTH * MAP_HEIGHT);
    //     int xpos = pos % MAP_WIDTH;
    //     int ypos = pos / MAP_WIDTH;
    //     cout << xpos << " " << ypos << endl;
    // }
    botRunr = createCycle(12, 64, 64, 9, 10);
    botRund = createCycle(11, 64, 64, 9, 10);
    botRunl = createCycle(10, 64, 64, 9, 10);
    botRunu = createCycle(9, 64, 64, 9, 10);
    setCurAnimation(botRunr);
    initObject("image/bots.png", ypos * 32, xpos * 32);
}

void botAI::solve(){
    rq.push(sr);
    cq.push(sc);
    visited[sr][sc] = true;
    r = rq.front();
    c = cq.front();
    rq.pop();
    cq.pop();
    if (reached){
        reached_end = true;
        return;
    }
    explore_neighbours(r,c);
    node_left_in_layer--;
    if (node_left_in_layer == 0){
        node_left_in_layer = nodes_in_next_layer;
        nodes_in_next_layer = 0;
    }
} 

void botAI::explore_neighbours(int r, int c){
    for (int i = 0; i < 4; i++){
        int rr = r + dr[i];
        int cc = c + dc[i];
        if (rr < 0 or cc < 0) continue;
        if (rr >= MAP_HEIGHT or cc >= MAP_HEIGHT) continue;
        if (visited[rr][cc]) continue;
        Rtraces[rr][cc] = r;
        Ctraces[rr][cc] = c;
        rq.push(rr);
        cq.push(cc);
        visited[rr][cc] = true;
        nodes_in_next_layer++;
    }
}
