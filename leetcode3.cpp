//
// Created by yqq3081 on 2020/2/6.
//
#include <iostream>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    vector<int> charvec(128, -1);
    int start = 0;
    int end = 0;
    int len = 0;
    int maxlen = 0;
    while(end <= s.size())
    {
        int tmp = charvec[(int)s[end]];
        if(tmp >= start)
        {
            start = tmp + 1;
            len = end - start;
        }
        charvec[(int)s[end]] = end;
        len++;
        end++;
        maxlen = max(len, maxlen);
    }
    return maxlen;
}

int main()
{
    string str = "abcbd";
    cout << lengthOfLongestSubstring(str);
    return 0;
}
