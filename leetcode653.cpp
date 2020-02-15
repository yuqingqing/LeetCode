//
// Created by yqq3081 on 2020/2/10.
//

#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
//非递归中序遍历
void midTravel(TreeNode* root, vector<int>& nums)
{
    TreeNode* curr = root;
    stack<TreeNode*> s;
    while(curr || !s.empty())
    {
        while(curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        nums.push_back(curr->val);
        s.pop();
        curr = curr->right;
    }
}

// 中序遍历存到数组，升序数组
void inorderTravel(TreeNode* root, vector<int>& nums) //递归遍历
{
    if(!root)
    {
        return ;
    }
    inorderTravel(root->left, nums);
    nums.push_back(root->val);
    inorderTravel(root->right, nums);
}

bool findTarget(TreeNode* root, int k)
{
    vector<int> nums;
    //inorderTravel(root, nums);
    midTravel(root, nums);
    int low = 0;
    int high = nums.size() - 1;
    while(low < high)
    {
        if(nums[low] + nums[high] == k)
        {
            return true;
        }
        else if(nums[low] < k - nums[high])
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    return false;
}

bool findTarget2(TreeNode* root, int k)
{
    vector<int> nums;
    map<int, int> idxmap;
    inorderTravel(root, nums);
    for(int i = 0; i < nums.size(); i++)
    {
        auto iter = idxmap.find(k - nums[i]);
        if(iter != idxmap.end())
        {
            return true;
        }
        idxmap.insert(pair<int,int>(nums[i], i));
    }
    return false;
}

int main()
{
    return 0;
}