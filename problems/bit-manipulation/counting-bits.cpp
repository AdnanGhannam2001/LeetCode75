/**
 * Problem:
 *  LeetCode 75 -> Bit Manipulation
 *  338. Counting Bits (Easy)
 *  https://leetcode.com/problems/counting-bits/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/counting-bits/submissions/1366785472?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      5ms
 *      Beats: 50.19%
 *  Memory
 *      9.25MB
 *      Beats: 69.02%
 */

#include <iostream>
#include <cassert>

#include <vector>

class Solution
{
public:
    std::vector<int> countBits(int n)
    {
        std::vector<int> results(n + 1, 0);
        std::size_t i = 0;

        do
        {
            results[i] = __builtin_popcount(i);
        } while (i++ < n);

        return results;
    }
};

int main()
{
    Solution solution;

    assert(solution.countBits(2) == std::vector({0, 1, 1}));
    assert(solution.countBits(5) == std::vector({0, 1, 1, 2, 1, 2}));
    assert(solution.countBits(0) == std::vector({0}));

    return 0;
}