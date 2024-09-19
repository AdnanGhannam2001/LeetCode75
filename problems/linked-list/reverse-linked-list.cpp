/**
 * Problem:
 *  LeetCode 75 -> Linked List
 *  206. Reverse Linked List (Easy)
 *  https://leetcode.com/problems/reverse-linked-list/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/reverse-linked-list/submissions/1366317816?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      4ms
 *      Beats: 71.15%
 *  Memory
 *      13.03MB
 *      Beats: 27.91%
 */

#include <iostream>
#include <cassert>

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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *prev = head,
                 *curr = head->next,
                 *next = nullptr;

        prev->next = nullptr;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
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
        solution.reverseList(node1);
    }

    {
        ListNode *node3 = new ListNode(3);
        ListNode *node2 = new ListNode(2, node3);
        ListNode *node1 = new ListNode(1, node2);
        solution.reverseList(node1);
    }

    {
        solution.reverseList(nullptr);
    }

    {
        ListNode *node1 = new ListNode(1);
        solution.reverseList(node1);
    }

    {
        ListNode *node7 = new ListNode(6);
        ListNode *node6 = new ListNode(2, node7);
        ListNode *node5 = new ListNode(1, node6);
        ListNode *node4 = new ListNode(7, node5);
        ListNode *node3 = new ListNode(4, node4);
        ListNode *node2 = new ListNode(3, node3);
        ListNode *node1 = new ListNode(1, node2);
        solution.reverseList(node1);
    }

    return 0;
}