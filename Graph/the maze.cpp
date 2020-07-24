/*
This problem was asked by Google.
Similar Question - Leetcode 490 The Maze - Medium Vs Easy depends
You are given an M by N matrix consisting of booleans that represents a board. Each True boolean represents a wall. Each False boolean represents a tile you can walk on.

Given this matrix, a start coordinate, and an end coordinate, return the minimum number of steps required to reach the end coordinate from the start. If there is no possible path, then return null. You can move up, left, down, and right. You cannot move through walls. 
You cannot wrap around the edges of the board.

For example, given the following board:

[[f, f, f, f],
[t, t, f, t],
[f, f, f, f],
[f, f, f, f]]
and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number of steps required to reach the end is 7, since we would need to go through (1, 2) 
because there is a wall everywhere else on the second row.

Copyright Lokeswara Rao Bonta - 2020
DS & Algo - Graph Section
*/

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#define T true
#define F false

using namespace std;
class Solution
{
public:
    int minNumOfSteps(const vector<vector<bool>> &maze, int start_x, int start_y, int end_x, 
                    int end_y)
    {
        auto valid = [&](int x_, int y_)
        {
            return (x_>=0 && x_ < maze.size() && y_ >= 0 && y_ < maze[0].size() && maze[x_][y_] != T);
        };
        std::vector<std::vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> distance(maze.size(), vector<int>(maze[0].size(), INT32_MAX - 1));
        unordered_set<int> visited;
        queue<pair<int, int>> bfs_queue;
        int m = maze.size();
        int n = maze[0].size();
        if (maze.size() == 0 || maze[0].size() == 0) return INT32_MAX;
        distance[start_x][start_y] = 0;
        bfs_queue.push(make_pair(start_x, start_y));
        visited.insert(start_x * m + start_y);
        while(!bfs_queue.empty())
        {
            auto coord = bfs_queue.front();
            bfs_queue.pop();
            int x = coord.first;
            int y = coord.second;
            if(x == end_x && y == end_y) return distance[x][y];
            for(auto dir : dirs)
            {
                if(valid(x + dir[0],y + dir[1]) && visited.find(m *(x + dir[0]) + y + dir[1]) == visited.end())
                {
                    visited.insert(m *(x + dir[0]) + y + dir[1]);
                    bfs_queue.push(make_pair(x+dir[0], y + dir[1]));
                    distance[x+dir[0]][y+dir[1]] = distance[x][y] + 1;
                }
            }
        }
        return INT32_MAX;
    }
};

int main()
{
    vector<vector<bool>> maze = {{F, F, F, F}, {F, T, F, T}, {F, F, F, F}, {F, F, F, F}};
    Solution S;
    int min_distance;
    min_distance = S.minNumOfSteps(maze, 0, 0, 3 ,0);
    cout << "Min Number of Steps is " <<  min_distance << endl;
    return 0;
}