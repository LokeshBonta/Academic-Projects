/*
Minimum steps to reach from given number N to 1
if a number is divisible by 2 then can jump to n/2
if a number is divisible by 3 then can jump to n/3
and
can jump to n-1
*/
/*
Copyright Lokeswara Rao Bonta - 2020
DS & Algo - Dynamic Programming Section
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
int memoMinSteps(int n, int *memo)
{
    if (n == 1)
    {
        memo[1] = 0;
        return 0;
    }
    if (memo[n] != 0)
        return memo[n];
    int result = memoMinSteps(n - 1, memo);
    if (n % 2 == 0)
        result = std::min(result, memoMinSteps(n / 2, memo));
    if (n % 3 == 0)
        result = std::min(result, memoMinSteps(n / 3, memo));
    memo[n] = result + 1;
    return memo[n];
}
int recMinsteps(int n)
{
    int result = 0;
    if (n == 1) // Base Case
        return 0;
    result = recMinsteps(n - 1);
    if (n % 2 == 0)
        result = std::min(result, recMinsteps(n / 2));
    if (n % 3 == 0)
        result = std::min(result, recMinsteps(n / 3));
    return result + 1;
}
int bottumUpMinSteps(int n, std::vector<int> &memo)
{
    memo[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i + 1 <= n)
            memo[i + 1] = std::min(memo[i + 1], memo[i] + 1);
        if (2 * i <= n)
            memo[2 * i] = std::min(memo[2 * i], memo[i] + 1);
        if (3 * i <= n)
            memo[3 * i] = std::min(memo[3 * i], memo[i] + 1);
    }
    return memo[n];
}
#define MAX_SIZE 1000000
int main(int argc, char *argv[])
{
    int n;
    std::cout << "Enter the number: " << std::endl;
    std::cin >> n;
    int memo[MAX_SIZE];
    //int min_steps = recMinsteps(n);
    //int min_steps = memoMinSteps(n, memo);
    std::vector<int> bu_array(n + 1, 100);
    int min_steps = bottumUpMinSteps(n, bu_array);
    std::cout << "Minimum number of steps to reach 1 is" << min_steps << std::endl;
    return 0;
}