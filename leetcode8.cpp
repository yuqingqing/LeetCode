//
// Created by yqq3081 on 2020/2/10.
//
#include <iostream>
using namespace std;

int myAtoi(string str) {
    int res = 0;
    int i = 0;
    int flag = 1; // flag为1正数， flag为0负数
    //1. 检查空白
    while(str[i] == ' ') i++;
    //2. 检查符号
    if(str[i] == '-') flag = 0;
    if(str[i] == '+' || str[i] == '-') i++;
    //3. 计算数字
    while(i < str.size() && isdigit(str[i])) {
        int r = str[i] - '0';
        //4. 处理溢出
        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7))
        {
            return flag ? INT_MAX : INT_MIN;
        }
        res = res * 10 + r;
        i++;
    }
    return flag ? res : -res;
}

int main()
{
    cout << myAtoi("12345") << endl;
    return 0;
}