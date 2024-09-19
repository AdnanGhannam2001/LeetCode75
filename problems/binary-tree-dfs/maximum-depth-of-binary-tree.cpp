/**
 * Problem:
 *  LeetCode 75 -> Binary Tree - DFS
 *  104. Maximum Depth of Binary Tree (Easy)
 *  https://leetcode.com/problems/maximum-depth-of-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/1369642193?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      4ms
 *      Beats: 75.73%
 *  Memory
 *      17.81MB
 *      Beats: 6.86%
 */

#include <iostream>
#include <cassert>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    inline int max(const int a, const int b)
    {
        return a > b ? a : b;
    }
public:
    int maxDepth(TreeNode *root)
    {
        return root != nullptr ? max(maxDepth(root->left), maxDepth(root->right)) : 0;
    }
};

int main()
{
    return 0;
}