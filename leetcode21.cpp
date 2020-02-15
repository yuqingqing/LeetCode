//
// Created by yqq3081 on 2020/2/13.
//

//21. 合并两个有序链表
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(-1);
    ListNode* l3 = head;
    while(l1 || l2)
    {
        if((l1 && l2) && (l1->val <= l2->val))
        {
            l3->next = l1;
            l1 = l1->next;
        }
        else if((l1 && l2) && (l1->val > l2->val))
        {
            l3->next = l2;
            l2 = l2->next;
        }
        else if(l1 == NULL && l2)
        {
            l3->next = l2;
            break;
        }
        else if(l2 == NULL && l1)
        {
            l3->next = l1;
            break;
        }
        l3 = l3->next;
    }
    ListNode* newList = head->next;
    delete head; //不然会有内存泄漏
    return newList;
}

int main()
{

    return 0;
}