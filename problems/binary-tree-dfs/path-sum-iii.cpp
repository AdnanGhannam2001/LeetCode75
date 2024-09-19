/**
 * Problem:
 *  LeetCode 75 -> Binary Tree - DFS
 *  437. Path Sum III (Medium)
 *  https://leetcode.com/problems/path-sum-iii/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/path-sum-iii/submissions/1369906072?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      12ms
 *      Beats: 80.68%
 *  Memory
 *      20.04MB
 *      Beats: 43.93%
 */

#include <iostream>
#include <cassert>

#include <list>

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
    int pathSumImpl(TreeNode *root, int targetSum, long acc, std::list<int> &list)
    {
        if (root == nullptr)
            return 0;

        list.push_back(root->val);
        acc += root->val;
        int equals = 0;
        {
            long curr = acc;
            for (auto item = list.begin(); item != list.end(); ++item)
            {
                if (curr == targetSum)
                {
                     equals++;
                }
                curr -= *item;
            }
        }

        int left = 0, right = 0;
        if (root->left != nullptr)
        {
            left = pathSumImpl(root->left, targetSum, acc, list);
            list.pop_back();
        }
        if (root->right != nullptr)
        {
            right = pathSumImpl(root->right, targetSum, acc, list);
            list.pop_back();
        }

        return equals + left + right;
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        std::list<int> list;
        return pathSumImpl(root, targetSum, 0L, list);
    }
};

int main()
{
    return 0;
}