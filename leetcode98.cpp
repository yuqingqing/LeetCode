//
// Created by yqq3081 on 2020/2/11.
//
#include <iostream>
#include <stack>
using namespace std;
/*
算法思想：由于二叉搜索树的性质，对其进行中序遍历为递增序列。故而，先对树进行中序遍历，将结点值存入向量中，然后判断判断向量元素是否递增即可。此处，中序遍历采用非递归实现。
值得注意的是，题目设定为左<根<右，那么就可以用中序遍历来做。但是测试用例里有左<=根<=右的情况，所以不能用上述方法做，理由如下：例如 [1,null,1] 与 [1,1]  它们遍历得出的结果一样，但第一个为BST，第二个不是。
故，利用它本身的性质来做，即左<根<右，初始化时带入系统最大值和最小值，在递归过程中换成它们自己的节点值，用long代替int就是为了包括int的边界条件。
*/
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

bool isValidBSTSub(TreeNode* root, long min, long max)
{
    if(root == NULL) return true;
    if(root->val <= min || root->val >= max) return false;
    return isValidBSTSub(root->left, min, root->val) && isValidBSTSub(root->right, root->val, max);
}

bool isValidBST(TreeNode* root)
{
    return isValidBSTSub(root, LONG_MIN, LONG_MAX);
}

bool isValidBST2(TreeNode* root) {
    TreeNode* tmp = root;
    stack<TreeNode*> s;
    int preval = INT_MIN;
    bool init = false;
    while(tmp || !s.empty())
    {
        while(tmp)
        {
            s.push(tmp);
            tmp = tmp->left;
        }
        tmp = s.top();
        if(init && tmp->val <  preval)
        {
            return false;
        }
        else
        {
            init = true;
            preval = tmp->val;
        }
        s.pop();
        tmp = tmp->right;
    }
    return true;
}

int main()
{

    return 0;
}


