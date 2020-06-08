/*
Walls and Gates Problem 286 LC - Medium

You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 2^31 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a Gate, that room should remain filled with INF

Have you met this question in a real interview?  
Example
Example1

Input:
[[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
Output:
[[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]

Explanation:
the 2D grid is:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
the answer is:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
Example2

Input:
[[0,-1],[2147483647,2147483647]]
Output:
[[0,-1],[1,2]]

Copyright Lokeswara Rao Bonta - 2020
DS & Algo - Graph Section
Famous Facebook Interview Problem
*/

#include<iostream>
#include<vector>

using namespace std;
class Solution
{
private:
    void dfs_helper(vector<vector<int>> &rooms, int x, int y, int distance)
    {
        if(x >= rooms[0].size() || y >= rooms.size() || x < 0 || y < 0 
                        || rooms[x][y] < distance)
            return;
        rooms[x][y] = distance;
        dfs_helper(rooms, x+1, y, distance + 1);
        dfs_helper(rooms, x, y+1, distance + 1);
        dfs_helper(rooms, x-1, y, distance + 1);
        dfs_helper(rooms, x, y-1, distance + 1);
    }
public:
    void wallsAndGates(vector<vector<int>> &rooms)
    {
        if (rooms.size() == 0 || rooms[0].size() == 0) return;
        for(int i = 0; i < rooms.size(); i++)
            for(int j = 0; j < rooms[0].size(); j++)
                if(rooms[i][j] == 0)
                    dfs_helper(rooms, i , j, 0);
    }
};

int main()
{
    vector<vector<int>> rooms;
    rooms.push_back({1<<30, -1, 0, 1<<30});
    rooms.push_back({1<<30, 1<<30, 1<<30, -1});
    rooms.push_back({1<<30, -1, 1<<30, -1});
    rooms.push_back({0, -1, 1<<30, 1<<30});
    Solution S;
    S.wallsAndGates(rooms);
    for(int i =0; i < rooms.size(); i++)
    {
        for(int j = 0; j < rooms.size(); j++)
        {
            cout << rooms[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}