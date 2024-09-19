/**
 * Problem:
 *  LeetCode 75 -> Binary Search Tree
 *  450. Delete Node in a BST (Medium)
 *  https://leetcode.com/problems/delete-node-in-a-bst/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/delete-node-in-a-bst/submissions/1373732009?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      15ms
 *      Beats: 97.60%
 *  Memory
 *      33.50MB
 *      Beats: 61.19%
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
    TreeNode *get_min_node(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        if (root->left == nullptr)
            return root;

        return get_min_node(root->left);
    }

    std::pair<TreeNode *, TreeNode *> get_node_with_parent(TreeNode *root, int val)
    {
        if (root == nullptr)
            return std::pair(nullptr, nullptr);
        if (root->val == val)
            return std::pair(nullptr, root);

        auto result = root->val > val
                          ? get_node_with_parent(root->left, val)
                          : get_node_with_parent(root->right, val);

        return result.first == nullptr && result.second != nullptr
                   ? std::pair(root, result.second)
                   : result;
    }

    TreeNode *deleteNodeImpl(TreeNode *root, int val)
    {
        if (root == nullptr)
            return root;

        auto [parent, node] = get_node_with_parent(root, val);

        if (node != nullptr)
        {
            TreeNode *&ptr =
                parent != nullptr
                    ? parent->left == node ? parent->left : parent->right
                    : root;

            if (node->left == nullptr && node->right == nullptr)
            {
                delete ptr;
                ptr = nullptr;
            }
            else if (node->left != nullptr && node->right != nullptr)
            {
                TreeNode *min_node = get_min_node(node->right);
                int min_node_value = min_node->val;
                deleteNodeImpl(node, min_node->val);
                node->val = min_node_value;
            }
            else
            {
                ptr = node->left != nullptr ? node->left : node->right;
                delete node;
            }
        }

        return root;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        return deleteNodeImpl(root, key);
    }
};

int main()
{
    return 0;
}