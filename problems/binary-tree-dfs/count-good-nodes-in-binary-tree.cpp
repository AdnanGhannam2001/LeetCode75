/**
 * Problem:
 *  LeetCode 75 -> Binary Tree - DFS
 *  1448. Count Good Nodes in Binary Tree (Medium)
 *  https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/count-good-nodes-in-binary-tree/submissions/1369674821?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      98ms
 *      Beats: 52.72%
 *  Memory
 *      84.96MB
 *      Beats: 40.38%
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
    int goodNodeImpl(TreeNode *root, int max)
    {
        if (root == nullptr)
            return 0;

        max = max > root->val ? max : root->val;
        return (root->val >= max ? 1 : 0) + goodNodeImpl(root->left, max) + goodNodeImpl(root->right, max);
    }

public:
    int goodNodes(TreeNode *root)
    {
        return 1 + goodNodeImpl(root->left, root->val) + goodNodeImpl(root->right, root->val);
    }
};

int main()
{
    return 0;
}