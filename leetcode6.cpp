//
// Created by yqq3081 on 2020/2/9.
//
#include <iostream>
using namespace std;

string convert(string s, int numRows) {
    string res = "";
    if(numRows == 1 || s.length() <= 2)
    {
        return s;
    }

    for(int currRow = 0; currRow < numRows; currRow++)
    {
        int interval;
        int firstInterval = (2 * numRows - 2) - 2 * currRow;
        int secondInterval = 2 * currRow;
        bool isFirst = true; // 除首位行会其它行会出现两种间隔的情况，
        int index = currRow;
        while(index < s.length())
        {
            interval = isFirst ? firstInterval : secondInterval; // 两种间隔
            if(interval == 0) // 首行和尾行不可能出现interval为0的情况，排除，取interval的另一种情况，也就是再算一次（isFirst取非）
            {
                isFirst = !isFirst;
                continue;
            }
            res += s[index];
            index += interval;
            isFirst = !isFirst;
        }
    }
    return res;
}

int main()
{
    return 0;
}
