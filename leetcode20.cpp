//
// Created by yqq3081 on 2020/2/13.
//

//20. 有效的括号
#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
    int len = s.size();
    if(len == 0)
    {
        return true;
    }
    if(len % 2 == 1)
    {
        return false;
    }
    stack<char> stk;
    for(int i = 0; i < len; i++)
    {
        if(stk.empty())
        {
            stk.push(s[i]);
            continue;
        }
        if((stk.top() == '(' && s[i] == ')') || (stk.top() == '[' && s[i] == ']') || (stk.top() == '{' && s[i] == '}'))
        {
            stk.pop();
        }
        else
        {
            stk.push(s[i]);
        }
    }
    return stk.empty();
}

int main()
{
    string str;
    while(cin >> str)
    {
        cout << isValid(str) << endl;
    }
    return 0;
}
