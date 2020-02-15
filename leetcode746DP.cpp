//
// Created by yqq3081 on 2020/2/11.
//
// 746. 使用最小花费爬楼梯
#include <iostream>
#include <vector>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int minCost1 = cost[0];
    int minCost2 = cost[1];
    int minCost;
    for(int i = 2; i < cost.size(); i++)
    {   // 最后一步，要么走两阶，要么走一阶, 加上当前的花费
        minCost = min(minCost1, minCost2)+ cost[i];
        minCost1 = minCost2;
        minCost2 = minCost;
    }
    // 最后一步，要么走两阶，要么走一阶
    return min(minCost1, minCost2);
}

int main()
{
    vector<int> cost = {10, 15, 20};
    cout << minCostClimbingStairs(cost);
    return 0;
}