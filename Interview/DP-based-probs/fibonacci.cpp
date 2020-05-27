/*
Fibanocci Number
1 1 2 3 5 8 13 21 34..........
fib(1) = 1
fib(2) = 1
fib(n) = fib(n-1) + fib(n-2)
*/
/*
Copyright Lokeswara Rao Bonta - 2020
DS & Algo - Dynamic Programming Section
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
long long memoFib(int n, std::vector<long> &memo)
{
    if(n == 1  || n == 2)
    {
        memo[n] = 1;
        return 1;
    }
    if(memo[n] != 0)
        return memo[n];
    memo[n] = memoFib(n-1, memo) + memoFib(n-2, memo);
    return memo[n];
}
long long recFib(int n)
{
    if(n == 1 || n == 2) // Base Case
        return 1;
    return(recFib(n-1) + recFib(n-2));
}
long long bottumUp(int n, std::vector<long> &memo)
{
    memo[1] = 1;
    memo[2] = 1;
    for(int i = 3; i <= n; i++)
        memo[i] = memo[i-1] + memo[i-2];
    return memo[n];
}
#define MAX_SIZE 1000000
int main(int argc, char *argv[])
{
    int n;
    std::cout << "Enter the number: " << std::endl;
    std::cin  >> n;
    //int memo[MAX_SIZE];
    //int fib = recFib(n);
    std::vector<long> bu_array(n+1, 0);
    long long fib = memoFib(n,  bu_array);
    long long fib_bu = bottumUp(n, bu_array);
    //int min_steps = bottumUpMinSteps(n, bu_array);
    std::cout << "Fibonacci is "<< fib << std::endl;
    std::cout << (fib_bu == fib) << std::endl;
    return 0;
}