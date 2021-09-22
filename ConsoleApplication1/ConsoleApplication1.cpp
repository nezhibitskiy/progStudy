#include <iostream>

 // Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
int rangeSum(TreeNode* root, int low, int high)
{
    int summ = 0;
    if (root->left != nullptr)
        summ = summ + rangeSum(root->left, low, high);
    if (root->right != nullptr)
        summ = summ + rangeSum(root->right, low, high);
    if (root->val <= high && root->val >= low)
        summ = summ + root->val;
    return summ;
}
};


int main()
{
    // std::cout << "Hello World!\n";
}

