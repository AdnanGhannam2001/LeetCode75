/**
 * Problem:
 *  LeetCode 75 -> Binary Search Tree
 *  700. Search in a Binary Search Tree (Easy)
 *  https://leetcode.com/problems/search-in-a-binary-search-tree/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/search-in-a-binary-search-tree/submissions/1372854103?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      24ms
 *      Beats: 89.77%
 *  Memory
 *      33.64MB
 *      Beats: 47.22%
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
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr || root->val == val) return root;

        return root->val > val
            ? searchBST(root->right, val)
            : searchBST(root->left, val);
    }
};

int main()
{
    return 0;
}