//
// Created by yqq3081 on 2020/2/11.
//
#include <iostream>
using namespace std;

int climbStairs(int n) {
    int dp_1 = 1;
    int dp_2 = 2;
    int dp;
    if(n == 1)
    {
        return dp_1;
    }
    else if(n == 2)
    {
        return dp_2;
    }
    for(int i = 3; i <= n; i++)
    {
        //最后一步，要么走一阶，要么走两阶
        dp = dp_2 + dp_1;
        dp_1 = dp_2;
        dp_2 = dp;
    }

    return dp;
}

int main()
{
    int n;
    while(cin >> n)
    {
        cout << climbStairs(n) << endl;
    }
    return 0;
}
