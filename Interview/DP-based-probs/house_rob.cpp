/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.

Copyright Lokeswara Rao Bonta - 2020
DS & Algo - Dynamic Programming Section
*/
#include<iostream>
#include<vector>
using namespace  std;
class Solution {
    public:
    int rob(vector<int>& nums) {
        if (nums.size() < 1) return 0;
        int even_sum = 0, odd_sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i % 2)
                odd_sum = max(odd_sum + nums[i] , even_sum);
            else
                even_sum = max(even_sum + nums[i] , odd_sum);
        }
        return max(odd_sum, even_sum);
    }
};

int main()
{
    std::vector<int> nums({2,7,9,3,1});
    Solution S;
    cout << "maximum robbery can be" << S.rob(nums) << endl ;
    return 0;
}