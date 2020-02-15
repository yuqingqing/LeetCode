//
// Created by yqq3081 on 2020/2/8.
//
#include <iostream>
#include <map>

using namespace std;

int getValue(char ch)
{
    switch(ch)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(string s) {
    int res = 0;
    int prenum = getValue(s[0]);;
    int num;
    for(int i = 1; i < s.length(); i++)
    {
        num = getValue(s[i]);
        if(prenum < num) //先与后一个数比较大小后再决定加prenum还是减
        {
            res -= prenum;
        } else{
            res += prenum;
        }
        prenum = num;
    }
    res += prenum;
    return res;
}

int romanToInt2(string s) {
    map<string, int> romDic = {{"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000},
                               {"IV", 3}, {"IX", 8}, {"XL", 30}, {"XC", 80}, {"CD", 300}, {"CM", 800}};
    int res = romDic[s.substr(0, 1)];
    for(int i = 1; i < s.length(); i++)
    {
        string two = s.substr(i - 1, 2);
        string one = s.substr(i, 1);
        res += romDic[two] ? romDic[two] : romDic[one];
    }
    return res;
}

int main()
{
    string s;
    while(cin >> s)
    {
        cout << romanToInt(s) << endl;
    }
    return 0;
}
