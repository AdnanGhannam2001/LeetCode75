/**
 * Problem:
 *  LeetCode 75 -> Queue
 *  933. Number of Recent Calls (Easy)
 *  https://leetcode.com/problems/number-of-recent-calls/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/number-of-recent-calls/submissions/1387552672?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      111ms
 *      Beats: 69.53%
 *  Memory
 *      62.51MB
 *      Beats: 28.43%
 */

#include <iostream>
#include <cassert>

#include <queue>

class RecentCounter
{
private:
    std::queue<int> m_queue;

    void cleanup(int t)
    {
        while (!m_queue.empty())
        {
            if (m_queue.front() >= t - 3000)
                break;
            m_queue.pop();
        }
    }

public:
    RecentCounter() {}

    int ping(int t)
    {
        cleanup(t);
        m_queue.push(t);

        return m_queue.size();
    }
};

int main()
{
    RecentCounter *obj = new RecentCounter();
    assert(obj->ping(1) == 1);
    assert(obj->ping(100) == 2);
    assert(obj->ping(3001) == 3);
    assert(obj->ping(3002) == 3);

    return 0;
}