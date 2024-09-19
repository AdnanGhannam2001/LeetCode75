/**
 * Problem:
 *  LeetCode 75 -> Binary Tree - BFS
 *  1161. Maximum Level Sum of a Binary Tree (Medium)
 *  https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/submissions/1372327578?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      477ms
 *      Beats: 5.06%
 *  Memory
 *      110.64MB
 *      Beats: 5.06%
 */

#include <iostream>
#include <cassert>

#include <unordered_map>
#include <algorithm>
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
    using SumMap = std::unordered_map<int, int>;
    using NodesQueue = std::queue<std::pair<TreeNode *, int>>;

    void maxLevelSumImpl(TreeNode *root, int level, SumMap &sum_map, NodesQueue &queue)
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

            auto sum = sum_map.find(front.second);
            if (sum != sum_map.end())
            {
                sum->second += front.first->val;
            }
            else
            {
                sum_map[front.second] = front.first->val;
            }

            maxLevelSumImpl(front.first, front.second + 1, sum_map, queue);
        }
    }

public:
    int maxLevelSum(TreeNode *root)
    {
        SumMap sum_map;
        NodesQueue queue;

        using SumMapPair = decltype(sum_map)::value_type;

        sum_map[1] = root->val;
        maxLevelSumImpl(root, 2, sum_map, queue);

        return std::max_element(sum_map.begin(), sum_map.end(), [](const SumMapPair &a, const SumMapPair &b) -> bool
                                { return a.second <= b.second; })
            ->first;
    }
};

int main()
{
    return 0;
}