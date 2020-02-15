//
// Created by yqq3081 on 2020/2/14.
//
//26. 删除排序数组中的重复项
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int i, j;
    // 设置两个指针，一个慢指针i，一个快指针j，
    // 当nums[i] != nums[j],将nums[++i] = nums[j]。
    for(i = 0, j = 1; j < nums.size(); j++)
    {
        if(nums[i] != nums[j])
        {
            nums[++i] = nums[j];
        }
    }
    return i + 1;
}
int removeDuplicates2(vector<int>& nums) {
    int newlen = nums.size();
    for(int i = 0; i < nums.size(); i++)
    {
        int j = i;

        while(j < (newlen - 1))
        {
            if(nums[j] == nums[j + 1])
            {
                j++;
            }
            else
            {
                break;
            }
        }
        if(j != i)
        {
            int len = j - i;
            for(;j < newlen; j++)
            {
                nums[j - len] = nums[j];
            }
            newlen -= len;
        }
    }
    return newlen;
}

int main()
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout << removeDuplicates(nums) << endl;
    return 0;
}
