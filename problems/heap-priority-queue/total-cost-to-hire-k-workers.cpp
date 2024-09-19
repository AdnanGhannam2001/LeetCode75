/**
 * Problem:
 *  LeetCode 75 -> Heap / Priority Queue
 *  2462. Total Cost to Hire K Workers (Medium)
 *  https://leetcode.com/problems/total-cost-to-hire-k-workers/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/total-cost-to-hire-k-workers/submissions/1384152970?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      124ms
 *      Beats: 52.88%
 *  Memory
 *      76.76MB
 *      Beats: 90.27%
 */

#include <iostream>
#include <cassert>

#include <vector>
#include <queue>
#include <list>

class Solution
{
public:
    long long totalCost(const std::vector<int> &costs, int k, int candidates)
    {
        std::size_t size = costs.size(),
                    x, y;
        long long result = 0LL;

        std::priority_queue<int, std::vector<int>, std::greater<>> queue1, queue2;

        for (x = 0; x < candidates && x < size; ++x)
        {
            queue1.push(costs[x]);
        }

        for (y = size - 1; y > size - candidates - 1 && y > x - 1; --y)
        {
            queue2.push(costs[y]);
        }

        x = candidates - 1,
        y = size - candidates;

        while (k-- && !(queue1.empty() && queue2.empty()))
        {
            if (queue2.empty() || (!queue1.empty() && queue1.top() <= queue2.top()))
            {
                result += queue1.top();
                queue1.pop();

                if (x < size - 1 && x < y - 1)
                    queue1.push(costs[++x]);
            }
            else
            {
                result += queue2.top();
                queue2.pop();

                if (x + 1 < y)
                    queue2.push(costs[--y]);
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;

    assert(solution.totalCost({17, 12, 10, 2, 7, 2, 11, 20, 8}, 3, 4) == 11);
    assert(solution.totalCost({1, 2, 4, 1}, 3, 3) == 4);
    assert(solution.totalCost({57,33,26,76,14,67,24,90,72,37,30}, 11, 2) == 526);
    assert(solution.totalCost({2,2,9,9,1,1,2,2}, 4, 1) == 8);
    assert(solution.totalCost({28,35,21,13,21,72,35,52,74,92,25,65,77,1,73,32,43,68,8,100,84,80,14,88,42,53,98,69,64,40,60,23,99,83,5,21,76,34}, 32, 12) == 1407);
    assert(solution.totalCost({18,64,12,21,21,78,36,58,88,58,99,26,92,91,53,10,24,25,20,92,73,63,51,65,87,6,17,32,14,42,46,65,43,9,75}, 13, 23) == 223);
    assert(solution.totalCost({1,2,4,1}, 3, 3) == 4);

    
    
    
    
    
    
    


    return 0;
}