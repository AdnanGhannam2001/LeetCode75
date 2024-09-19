/**
 * Problem:
 *  LeetCode 75 -> Linked List
 *  328. Odd Even Linked List (Medium)
 *  https://leetcode.com/problems/odd-even-linked-list/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/odd-even-linked-list/submissions/1366286363?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      13ms
 *      Beats: 14.12%
 *  Memory
 *      15.46MB
 *      Beats: 42.24%
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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr) return head;

        ListNode *tail = head,
                 *curr = head,
                 *prev = nullptr,
                 *tmp = nullptr;

        std::size_t length = 0,
                    i = 0;

        while ((curr = curr->next) != nullptr)
        {
            ++length;
            tail = curr;
        }
        curr = head;

        while (i++ <= length)
        {
            if (curr == tail) break;
            else if (i % 2 == 0)
            {
                prev->next = curr->next;
                tmp = curr->next;
                tail->next = curr;
                curr->next = nullptr;
                tail = curr;
                curr = tmp;
                tmp = nullptr;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
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
        solution.oddEvenList(node1);
    }

    {
        ListNode *node3 = new ListNode(3);
        ListNode *node2 = new ListNode(2, node3);
        ListNode *node1 = new ListNode(1, node2);
        solution.oddEvenList(node1);
    }

    {
        ListNode *node1 = new ListNode(1);
        solution.oddEvenList(node1);
    }

    {
        ListNode *node7 = new ListNode(7);
        ListNode *node6 = new ListNode(4, node7);
        ListNode *node5 = new ListNode(6, node6);
        ListNode *node4 = new ListNode(5, node5);
        ListNode *node3 = new ListNode(3, node4);
        ListNode *node2 = new ListNode(1, node3);
        ListNode *node1 = new ListNode(2, node2);
        solution.oddEvenList(node1);
    }
    
    {
        ListNode *node2 = new ListNode(2);
        ListNode *node1 = new ListNode(1, node2);
        solution.oddEvenList(node1);
    }

    return 0;
}