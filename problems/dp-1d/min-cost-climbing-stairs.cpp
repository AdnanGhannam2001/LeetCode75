/**
 * Problem:
 *  LeetCode 75 -> DP - 1D
 *  746. Min Cost Climbing Stairs (Easy)
 *  https://leetcode.com/problems/min-cost-climbing-stairs/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/min-cost-climbing-stairs/submissions/1386502235?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      3ms
 *      Beats: 80.33%
 *  Memory
 *      16.64MB
 *      Beats: 74.24%
 */

#include <iostream>
#include <cassert>

#include <vector>

class Solution
{
public:
    int minCostClimbingStairs(const std::vector<int> &cost)
    {
        int16_t size = cost.size();
        int costs[size];
        costs[size - 1] = cost[size - 1],
        costs[size - 2] = cost[size - 2];

        for (int16_t i = size - 3; i >= 0; --i)
            costs[i] = std::min(costs[i + 1], costs[i + 2]) + cost[i];

        return std::min(costs[0], costs[1]);
    }
};

int main()
{
    Solution solution;

    // std::cout << solution.minCostClimbingStairs({10, 15, 20}) << "\n";
    std::cout << solution.minCostClimbingStairs({1, 100, 1, 1, 1, 100, 1, 1, 100, 1}) << "\n";

    return 0;
}