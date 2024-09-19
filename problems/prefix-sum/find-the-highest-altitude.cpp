/**
 * Problem:
 *  LeetCode 75 -> Prefix Sum
 *  1732. Find the Highest Altitude (Easy)
 *  https://leetcode.com/problems/find-the-highest-altitude/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/find-the-highest-altitude/submissions/1387544405?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      2ms
 *      Beats: 46.92%
 *  Memory
 *      10.12MB
 *      Beats: 32.82%
 */

#include <iostream>
#include <cassert>

#include <vector>

class Solution
{
public:
    int largestAltitude(const std::vector<int> &gain)
    {
        int16_t max = 0,
                acc = 0;

        for (const auto &x : gain)
            acc += x,
            max = max > acc ? max : acc;

        return max;
    }
};

int main()
{
    Solution solution;

    assert(solution.largestAltitude(std::vector<int>({-5, 1, 5, 0, -7})) == 1);
    assert(solution.largestAltitude(std::vector<int>({-4, -3, -2, -1, 4, 3, 2})) == 4);
    assert(solution.largestAltitude(std::vector<int>({0, 1, 2, 3, 4, 5})) == 15);
    assert(solution.largestAltitude(std::vector<int>({1, 2, 3, 4, 5})) == 15);
    assert(solution.largestAltitude(std::vector<int>({-1, -2, -3, -4, -5})) == 0);
    assert(solution.largestAltitude(std::vector<int>({0, 0, 0, 0, 0})) == 0);
    assert(solution.largestAltitude(std::vector<int>({-1, 2, 3, -2, 4, -1})) == 6);
    assert(solution.largestAltitude(std::vector<int>({5, -1, -2, 3, 2, -4})) == 8);
    assert(solution.largestAltitude(std::vector<int>({-2, -1, 0, 1, 2, 3})) == 3);
    assert(solution.largestAltitude(std::vector<int>({10, -5, 2, -3, 4})) == 10);

    return 0;
}
