/*
LC-256 Paint House 
LinkedIn - Popular
There are a row of n houses, each house can be painted with one of the 
three colors: red, blue or green. The cost of painting each house with 
a certain color is different. You have to paint all the houses such 
that no two adjacent houses have the same color.
The cost of painting each house with a certain color is 
represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting 
house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, 
and so on... Find the minimum cost to paint all houses.
Note:
All costs are positive integers.

Thought process:
Sub-problem: find the minimum cost to paint the houses up to current house in red, blue or green.
Function:
Red: min(f[i - 11][1], f[i - 1][2]) + costs[i][0].
Blue: min(f[i - 1][0], f[i - 1][2]) + costs[i][1].
Green: min(f[i - 1][0], f[i - 1][1]) + costs[i][2].
Initialization: f[0][i] = 0.
Answer: min(f[costs.length][i]).

Copyright Lokeswara Rao Bonta - 2020
DS & Algo - Dynamic Programming Section - Matrix  Section
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int paintHouse(std::vector<std::vector<int>> costs)
    {
        if (costs.size() == 0)
            return 0;
        int r1, g1, b1;
        int r = costs[0][0], g = costs[0][1], b = costs[0][2];
        for (int i = 1; i < costs.size(); i++)
        {
            r1  = costs[i][0] + std::min(g, b);
            g1  = costs[i][1] + std::min(r, b);
            b1  = costs[i][2] + std::min(r, g);
            r = r1; g = g1; b = b1;
        }
        return std::min(r, std::min(g, b));
    }
};

int main()
{
    std::vector<std::vector<int>> costs {{17, 2, 17}, {16, 16, 5}, {14, 3, 19}};
    Solution S;
    std::cout << "Minimum cost to paint houses : " << S.paintHouse(costs) << std::endl;
    return 0;
}
