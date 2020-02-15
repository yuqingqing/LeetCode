//
// Created by yqq3081 on 2020/2/15.
//
#include <iostream>
using namespace std;

// 求子串的前缀表
void prefixTable(string needle, int prefix[], int n)
{
    int i = 1;
    int len = 0; // 最长公共前缀长度
    prefix[0] = 0;
    while(i < n)
    {
        if(needle[i] == needle[len])
        {
            len++;
            prefix[i] = len;
            i++;
        }
        else
        {
            if(len > 0)
            {   // 上一最长公共前缀，len即是长度，也是下标
                len = prefix[len - 1];
            }
            else
            {
                prefix[i] = 0;
                i++;
            }
        }
    }
    for(int i = n - 1; i > 0; --i)
    {
        prefix[i] = prefix[i - 1];
    }
    prefix[0] = -1;
}

int strStr(string haystack, string needle) {
    int m = haystack.size();
    int n = needle.size();
    if(n == 0 && m == 0)
    {
        return 0;
    }
    int prefix[n]; // 子串的前缀表
    prefixTable(needle, prefix, n);
    int i = 0; // haystack的开头
    int j = 0; // 子串needle的开头

    while(i < m)
    {
        if(needle[j] == haystack[i])
        {
            if(j == n - 1) // 子串都匹配上了
            {
                return (i - j);
            }
            if(n - j > m - i)  // 未匹配的子串长度比haystack的剩余长度长，可提前结束
            {
                return -1;
            }
            i++;
            j++;
        }
        else
        {
            j = prefix[j]; // 跳到子串待比较位置
            if(j == -1)
            {
                i++;
                j++;
            }
        }
    }
    return -1;
}

int main()
{
    string sub = "ABABCABAA";
    string str = "ABABABCABAAC";
    cout << strStr(str, sub);
    return 0;
}
