/**
 * Problem:
 *  LeetCode 75 -> Linked List
 *  2095. Delete the Middle Node of a Linked List (Medium)
 *  https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/submissions/1366258539?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      622ms
 *      Beats: 14.99%
 *  Memory
 *      299.76MB
 *      Beats: 44.70%
 */

#include <iostream>
#include <cassert>
#include <memory>

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
    ListNode* deleteMiddle(ListNode* head)
    {
        std::size_t length = 1,
                    i = 0;
        ListNode *curr = head,
                 *prev = head,
                 *tmp = nullptr;

        while ((curr = curr->next) != nullptr && length++)
            ;
        curr = head;

        while (i++ != length/2)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr->next != nullptr)
        {
            tmp = curr->next;
        }
        prev->next = tmp;
        tmp = nullptr;
        curr = nullptr;
        delete curr;

        return length == 1 ? nullptr : head;
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
        solution.deleteMiddle(node1);
    }

    {
        ListNode *node3 = new ListNode(3);
        ListNode *node2 = new ListNode(2, node3);
        ListNode *node1 = new ListNode(1, node2);
        solution.deleteMiddle(node1);
    }

    {
        ListNode *node1 = new ListNode(1);
        solution.deleteMiddle(node1);
    }

    {
        ListNode *node7 = new ListNode(6);
        ListNode *node6 = new ListNode(2, node7);
        ListNode *node5 = new ListNode(1, node6);
        ListNode *node4 = new ListNode(7, node5);
        ListNode *node3 = new ListNode(4, node4);
        ListNode *node2 = new ListNode(3, node3);
        ListNode *node1 = new ListNode(1, node2);
        solution.deleteMiddle(node1);
    }

    return 0;
}