
/*
LC -322. Coin Change 
Medium
You are given coins of different denominations and a total amount of money amount.
 Write a function to compute the fewest number of coins that you need to make up 
 that amount. If that amount of money cannot be made up by any combination of the 
 coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            for(int coin : coins)
                if(coin <= i)
                    dp[i] = min(dp[i], dp[i - coin ]+ 1);
                else
                    break;
        }
        return dp[amount] > amount? -1: dp[amount];
    }
};

int main()
{
    std::vector<int> coins{1, 2, 5};
    int amount;
    std::cout << "Enter the amount" << endl;
    cin >> amount;
    Solution S;
    cout << "Minimum number of coins required " << S.coinChange(coins, amount) << endl;
}