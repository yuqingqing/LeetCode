//
// Created by yqq3081 on 2020/2/15.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void prefix_table(char pattern[], int prefix[], int n)
{
    prefix[0] = 0;
    int len = 0;
    int i = 1;
    while(i < n)
    {
        if(pattern[i] == pattern[len])
        {
            len++;
            prefix[i] = len;
            i++;
        }
        else
        {
            if(len > 0)
            {
                len = prefix[len - 1];
            }
            else
            {
                prefix[i] = 0; // <=> prefix[i] = len; 此时len == 0
                i++;
            }
        }
    }
}

void move_prefix_table(int prefix[], int n)
{
    for(int i = n - 1; i > 0; --i)
    {
        prefix[i] = prefix[i - 1];
    }
    prefix[0] = -1;
}

void kmp_search(char text[], char pattern[])
{
    // text[i]        len(text): m
    // pattern[j]  len(pattern): n
    int m = strlen(text);
    int n = strlen(pattern);
    int* prefix = (int *)malloc(sizeof(int) * n);
    prefix_table(pattern, prefix, n);
    move_prefix_table(prefix, n);

    int i = 0;
    int j = 0;
    while(i < m)
    {
        if((j == n - 1) && (text[i] == pattern[j]))
        {
            printf("Found pattern at %d\n", i - j); // 此时，i - j 等价于 i - (n - 1)
            j = prefix[j]; // 继续寻找下一个匹配的子串位置
            if(n - j > m - i) // 若未比较的pattern长度已超出text剩下的长度，可提前结束比较
            {
                break;
            }
        }
        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            j = prefix[j];
            if(j == -1)
            {
                j++;
                i++;
            }
        }
    }
}

int main()
{
    char pattern[] = "ABABCABAA";
    char text[]    = "ABABABCABAAC";
    kmp_search(text, pattern);
    return 0;
}
