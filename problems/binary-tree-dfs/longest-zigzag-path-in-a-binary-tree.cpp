/**
 * Problem:
 *  LeetCode 75 -> Binary Tree - DFS
 *  1372. Longest ZigZag Path in a Binary Tree (Medium)
 *  https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/submissions/1371156108?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      121ms
 *      Beats: 46.48%
 *  Memory
 *      93.38MB
 *      Beats: 25.21%
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
    using Direction =
        enum {
            Left,
            Right
        };

    inline int max(int a, int b)
    {
        return a > b ? a : b;
    }

    int longestZigZagImpl(TreeNode *root, Direction direction, int longest)
    {
        if (root == nullptr)
            return longest;

        return max(
            longestZigZagImpl(root->left, Left, (direction == Left ? 0 : longest + 1)),
            longestZigZagImpl(root->right, Right, (direction == Right ? 0 : longest + 1)));
    }

public:
    int longestZigZag(TreeNode *root)
    {
        return root != nullptr
                   ? max(longestZigZagImpl(root->left, Left, 0), longestZigZagImpl(root->right, Right, 0))
                   : 0;
    }
};

int main()
{
    return 0;
}