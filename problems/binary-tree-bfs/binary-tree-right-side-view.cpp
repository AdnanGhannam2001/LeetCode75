/**
 * Problem:
 *  LeetCode 75 -> Binary Tree - BFS
 *  199. Binary Tree Right Side View (Medium)
 *  https://leetcode.com/problems/binary-tree-right-side-view/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/binary-tree-right-side-view/submissions/1371814286?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      0ms
 *      Beats: 100.00%
 *  Memory
 *      14.94MB
 *      Beats: 9.11%
 */

#include <iostream>
#include <cassert>

#include <vector>
#include <queue>

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
    using NodesQueue = std::queue<std::pair<TreeNode *, int>>;

    void rightSideViewImpl(TreeNode *root, int level, std::vector<int> &results, NodesQueue &queue)
    {
        if (root == nullptr)
            return;

        if (root->left != nullptr)
            queue.push({root->left, level});
        if (root->right != nullptr)
            queue.push({root->right, level});

        if (!queue.empty())
        {
            auto front = queue.front();
            queue.pop();
            if (queue.empty() || front.second < queue.front().second)
            {
                results.push_back(front.first->val);
            }

            rightSideViewImpl(front.first, front.second + 1, results, queue);
        }
    }

public:
    std::vector<int> rightSideView(TreeNode *root)
    {
        std::vector<int> results;
        NodesQueue queue;

        if (root != nullptr) results.push_back(root->val);
        rightSideViewImpl(root, 0, results, queue);

        return results;
    }
};

int main()
{
    return 0;
}