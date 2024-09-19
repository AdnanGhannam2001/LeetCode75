/**
 * Problem:
 *  LeetCode 75 -> Heap / Priority Queue
 *  215. Kth Largest Element in an Array (Medium)
 *  https://leetcode.com/problems/kth-largest-element-in-an-array/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/smallest-number-in-infinite-set/submissions/1382169453?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      59ms
 *      Beats: 77.99%
 *  Memory
 *      41.59MB
 *      Beats: 62.51%
 * 
 * Notes:
 *  - Didn't use std::set, because that would make things easier
 */

#include <iostream>
#include <cassert>

#include <list>

class SmallestInfiniteSet
{
private:
    using const_iterator = std::list<int>::const_iterator;
    std::list<int> m_container;
    int m_last;

public:
    SmallestInfiniteSet() : m_last(1) {}

    void addBack(int num)
    {
        const_iterator citer = m_container.begin();
        while (*citer < num && citer != m_container.end())
            citer++;
        if (*citer != num) m_container.insert(citer, num);
    }

    int popSmallest()
    {
        int val = m_last;
        if (!m_container.empty() && m_container.front() <= m_last)
        {
            val = m_container.front();
            m_container.pop_front();
        }
        if (val >= m_last)
            m_last++;

        return val;
    }
};

int main()
{
    SmallestInfiniteSet set;

    set.addBack(2);
    set.popSmallest(); // 1
    set.popSmallest(); // *2
    set.popSmallest(); // 3
    set.addBack(1);    // *1
    set.popSmallest(); // 1
    set.popSmallest(); // 4
    set.popSmallest(); // 5

    return 0;
}