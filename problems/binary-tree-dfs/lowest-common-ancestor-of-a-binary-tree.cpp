/**
 * Problem:
 *  LeetCode 75 -> Binary Tree - DFS
 *  236. Lowest Common Ancestor of a Binary Tree (Medium)
 *  https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/1371220208?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      8ms
 *      Beats: 91.69%
 *  Memory
 *      16.51MB
 *      Beats: 13.71%
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
    std::pair<TreeNode *, bool> lowestCommonAncestorImpl(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        if (root == nullptr)
            return {nullptr, false};

        auto left = lowestCommonAncestorImpl(root->left, p, q);
        auto right = lowestCommonAncestorImpl(root->right, p, q);

        if (left.first != nullptr)
            return left;
        if (right.first != nullptr)
            return right;

        if ((left.second && right.second) ||
            ((root->val == p->val || root->val == q->val) && (left.second || right.second)))
        {
            return {root, true};
        }

        return {
            (left.first != nullptr ? left.first : right.first),
            (left.second || right.second || root->val == p->val || root->val == q->val)};
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return lowestCommonAncestorImpl(root, p, q).first;
    }
};

int main()
{
    return 0;
}