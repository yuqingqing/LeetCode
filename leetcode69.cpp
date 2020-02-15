//
// Created by yqq3081 on 2020/2/11.
//
//求x的平方根
#include <iostream>
using namespace std;

int mySqrt(int x)
{
    //x的平方根比x的一半要小，0,1除外
    //于是x的平方根就落在了[1, x/2+1]这个区间，用二分查找在这个区间里找。
    if(x <= 1) return x;
    long low = 1;
    long high = x / 2 + 1;
    long mid;
    while(low < high)
    {
        mid = (low + high) / 2;
        if(x / mid >= mid && x / (mid + 1) < (mid + 1))
        {
            return mid;
        }
        else if(x / mid > mid)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    int n;
    while(cin >> n)
    {
        cout << mySqrt(n) << endl;
    }
    return 0;
}