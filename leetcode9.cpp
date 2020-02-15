//
// Created by yqq3081 on 2020/2/5.
//
#include <iostream>
using namespace std;

class Solution{
public:
    bool isPalindrome(int x){
        if(x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }
        int a = 0;
        int t = x;
        while(x)
        {
            a = a * 10 +  x % 10;
            x = x / 10;
        }
        return a == t ;
    }
};


class Solution2 {
public:
    bool isPalindrome(int x)
    {
        bool flag = false;
        if(x < 0)
        {
            flag = false;
        }
        else if(x == 0)
        {
            flag = true;
        }
        else
        {
            int a[16] = {0};
            int i = 0;
            while(x)
            {
                a[i++] = x % 10;
                x = x / 10;
            }
            int j;
            for(j = 0; j < i / 2 + 1; j++)
            {
                if(a[j] != a[i - j - 1])
                {
                    flag =  false;
                    break;
                }
            }
            if(j >= i / 2 + 1)
            {
                flag = true;
            }
        }
        return flag;
    }
};

int main()
{
    Solution sol;
    cout << sol.isPalindrome(10) << endl;
    return 0;
}