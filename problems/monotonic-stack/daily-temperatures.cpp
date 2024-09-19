/**
 * Problem:
 *  LeetCode 75 -> Monotonic Stack
 *  739. Daily Temperatures (Medium)
 *  https://leetcode.com/problems/daily-temperatures/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/daily-temperatures/submissions/1363028251?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      125ms
 *      Beats: 39.98%
 *  Memory
 *      110.22MB
 *      Beats: 6.68%
 */

#include <iostream>
#include <cassert>

#include <vector>
#include <stack>

class Solution
{
public:
    std::vector<int> dailyTemperatures(const std::vector<int> &temperatures)
    {
        std::stack<std::pair<int, int>> stack;

        std::size_t size = temperatures.size();
        std::vector<int> answers(size, 0);

        for (std::size_t i = 0; i < size; i++)
        {
            while (!stack.empty() && stack.top().second < temperatures[i])
            {
                std::pair<int, int> top = stack.top();
                stack.pop();
                answers[top.first] = i - top.first;
            }

            stack.push({i, temperatures[i]});
        }

        return answers;
    }
};

int main()
{
    Solution solution;

    assert(solution.dailyTemperatures(std::vector({73, 74, 75, 71, 69, 72, 76, 73})) == std::vector({1, 1, 4, 2, 1, 1, 0, 0}));
    assert(solution.dailyTemperatures(std::vector({30,40,50,60})) == std::vector({1, 1, 1, 0}));

    return 0;
}