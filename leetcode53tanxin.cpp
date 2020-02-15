//
// Created by yqq3081 on 2020/2/11.
//

#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int res = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        res = max(res, sum);
        if(sum < 0)
        {
            sum = 0;
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums);
    return 0;
}
