/**
 * Problem:
 *  LeetCode 75 -> DP - 1D
 *  790. Domino and Tromino Tiling (Medium)
 *  https://leetcode.com/problems/domino-and-tromino-tiling/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/domino-and-tromino-tiling/submissions/1386506977?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      2ms
 *      Beats: 53.58%
 *  Memory
 *      7.26MB
 *      Beats: 98.55%
 */

#include <iostream>
#include <cassert>

#define MOD 1000000007

class Solution
{
public:
    int numTilings(int n)
    {
        int values[n];
        values[0] = 1, values[1] = 2, values[2] = 5;

        for (uint16_t i = 3; i < n; ++i)
            values[i] = (2L * values[i - 1] + values[i - 3]) % MOD;

        return values[n - 1];
    }
};

int main()
{
    Solution solution;

    std::cout << solution.numTilings(5) << "\n";
    std::cout << solution.numTilings(1000) << "\n";

    return 0;
}