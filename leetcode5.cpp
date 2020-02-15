//
// Created by yqq3081 on 2020/2/8.
//
#include <iostream>
using namespace std;

string longestPalindrome(string s)
{
    int len = s.size();
    if(len == 0 || len == 1) return s;
    int dp[len][len] = {0}; //这里要初始化为0
    int max = 1; // 回文串最大长度
    int start = 0; // 回文串起始位置
    for(int i = 0; i < len; i++)
    {
        dp[i][i] = 1; // 1) 单个字符的子串
        if(s[i] == s[i + 1] && i < len - 1) // 2) 两个字符的子串
        {
            dp[i][i + 1] = 1;
            max = 2;
            start = i;
        }
    }
    // 3) >=3个字符的子串
    for(int l = 3; l <= len; l++)
    {
        for(int i = 0; i + l - 1 < len; i++)
        {
            int j = i + l - 1;
            if(s[i] == s[j] && dp[i + 1][j - 1] == 1)
            {
                dp[i][j] = 1;
                start = i;
                max = l;
            }
        }
    }
    return s.substr(start, max);
}

int main()
{
    string str;
    while(cin >> str)
    {
        cout << longestPalindrome(str) << endl;
    }
    return 0;
}
