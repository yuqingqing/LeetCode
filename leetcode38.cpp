//
// Created by yqq3081 on 2020/2/13.
//
//38. 外观数列
#include <iostream>
using namespace std;

string countAndSayCore(string s)
{
    string res;
    size_t idx  = 0;
    while(idx < s.size())
    {
        int cnt = 1;
        while(s[idx] == s[idx + 1])
        {
            cnt++;
            idx++;
        }
        res += to_string(cnt);
        res += s[idx];
        idx++;
    }
    return res;
}

string countAndSay(int n)
{
    int i = 1;
    string s = to_string(1);
    while(i < n)
    {
        s = countAndSayCore(s);
        i++;
    }
    return s;
}

int main()
{
    int n;
    while(cin >> n)
    {
        cout << countAndSay(n) << endl;
    }
    return 0;
}
