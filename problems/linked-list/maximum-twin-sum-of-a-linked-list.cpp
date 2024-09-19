/**
 * Problem:
 *  LeetCode 75 -> Linked List
 *  2130. Maximum Twin Sum of a Linked List (Medium)
 *  https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/submissions/1366336217?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      175ms
 *      Beats: 72.31%
 *  Memory
 *      122.00MB
 *      Beats: 46.70%
 */

#include <iostream>
#include <cassert>

#include <stack>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int pairSum(ListNode *head)
    {
        std::size_t length = 1,
                    half = 0,
                    i = 0,
                    max = 0,
                    value = 0;

        ListNode *curr = head;

        while ((curr = curr->next) != nullptr && ++length)
            ;

        std::stack<int> stack;

        half = length / 2;
        curr = head;
        while (i++ < half)
        {
            stack.push(curr->val);
            curr = curr->next;
        }

        while (i++ <= length)
        {
            value = curr->val + stack.top();
            max = max > value ? max : value;
            stack.pop();
            curr = curr->next;
        }

        return max;
    }
};

int main()
{
    Solution solution;

    {
        ListNode *node4 = new ListNode(4);
        ListNode *node3 = new ListNode(3, node4);
        ListNode *node2 = new ListNode(2, node3);
        ListNode *node1 = new ListNode(1, node2);
        assert(solution.pairSum(node1) == 5);
    }

    {
        ListNode *node2 = new ListNode(2);
        ListNode *node1 = new ListNode(1, node2);
        assert(solution.pairSum(node1) == 3);
    }

    {
        ListNode *node6 = new ListNode(6);
        ListNode *node5 = new ListNode(1, node6);
        ListNode *node4 = new ListNode(7, node5);
        ListNode *node3 = new ListNode(4, node4);
        ListNode *node2 = new ListNode(3, node3);
        ListNode *node1 = new ListNode(1, node2);
        assert(solution.pairSum(node1) == 11);
    }

    return 0;
}