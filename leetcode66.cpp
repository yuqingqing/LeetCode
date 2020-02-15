//
// Created by yqq3081 on 2020/2/11.
//
#include <iostream>
#include <vector>
using namespace std;

//leetcode88
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (m == 0)
    {
        for (int i = 0; i < n; i++)
        {
            nums1[i] = nums2[i];
        }
        return;
    }
    int i = m - 1; // nums1 非零元素尾
    int j = n - 1; // nums2 元素尾
    int k = m + n - 1; // 排序后的所有元素尾
    while(i >= 0 && j >= 0)
    {
        if(nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    //当原数组nums1中元素排序完 但数组nums2中元素未被合并完 出现的情况
    while(j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}


void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = 0;
    int j = 0;
    while(j < n)
    {
        while(nums1[i] <= nums2[j] && i < m)
        {
            i++;
        }
        if(nums1[i] > nums2[j])
        {
            swap(nums1[i], nums2[j]);
            j++;
        }
        if(i == m && j < n)
        {
            for(; j < n;j++, i++)
            {
                nums1[i] = nums2[j];
            }
        }
    }
}

vector<int> plusOne(vector<int>& digits) {
    for(int i = digits.size() - 1; i >= 0; i--)
    {
        if(digits[i] == 9)
        {
            digits[i] = 0;
        }
        else
        {
            digits[i]++;
            return digits;
        }
    }
    digits.push_back(0);
    digits[0] = 1;
    return digits;
}

int main()
{
    vector<int> digits = {1, 2, 3};

    return 0;
}
