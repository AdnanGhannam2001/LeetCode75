/**
 * Problem:
 *  LeetCode 75 -> Binary Tree - DFS
 *  872. Leaf-Similar Trees (Easy)
 *  https://leetcode.com/problems/leaf-similar-trees/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/leaf-similar-trees/submissions/1369659871?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      0ms
 *      Beats: 100.00%
 *  Memory
 *      14.56MB
 *      Beats: 43.79%
 */

#include <iostream>
#include <cassert>

#include <vector>

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
    void collect_leaves(TreeNode *root, std::vector<int> &leaves)
    {
        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr)
        {
            leaves.push_back(root->val);
            return;
        }

        collect_leaves(root->left, leaves);
        collect_leaves(root->right, leaves);
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        std::vector<int> leaves1,
            leaves2;

        collect_leaves(root1, leaves1);
        collect_leaves(root2, leaves2);

        uint8_t size = leaves1.size();

        if (size != leaves2.size())
            return false;

        for (uint8_t i = 0; i < size; ++i)
        {
            if (leaves1[i] != leaves2[i])
                return false;
        }

        return true;
    }
};

int main()
{
    return 0;
}