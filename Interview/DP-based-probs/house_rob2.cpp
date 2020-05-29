/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.
Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Copyright Lokeswara Rao Bonta - 2020
DS & Algo - Dynamic Programming Section
*/
#include<iostream>
#include<vector>
using namespace  std;
class Solution {
private:
    int rob_helper(vector<int> &nums, int start, int end)
    {
        if(end - start < 0) return 0;
        if (start == end && start < nums.size()) return nums[start];
        int even_sum = 0, odd_sum = 0;
        for(int i = start; i < end; i++)
        {
            if(i%2)
                odd_sum =  max(odd_sum + nums[i] , even_sum);
            else
                even_sum = max(even_sum + nums[i], odd_sum);
        }
        return max(even_sum, odd_sum);
    }
public:
    int rob(vector<int>& nums) {
        return max(rob_helper(nums, 0, nums.size()-1), rob_helper(nums, 1, nums.size()));
    }
};

int main()
{
    std::vector<int> nums({24,7,9,3,24});
    Solution S;
    cout << "maximum robbery can be" << S.rob(nums) << endl ;
    return 0;
}