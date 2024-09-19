/**
 * Problem:
 *  LeetCode 75 -> DP - 1D
 *  1137. N-th Tribonacci Number (Easy)
 *  https://leetcode.com/problems/n-th-tribonacci-number/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/n-th-tribonacci-number/submissions/1386492355?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      2ms
 *      Beats: 52.01%
 *  Memory
 *      7.24MB
 *      Beats: 94.69%
 */

#include <iostream>
#include <cassert>

class Solution
{
public:
    int tribonacci(int n)
    {
        int values[n + 3];
        values[0] = 0, values[1] = 1, values[2] = 1;

        for (uint8_t i = 3; i <= n; ++i)
            values[i] = values[i - 1] + values[i - 2] + values[i - 3];

        return values[n];
    }
};

int main()
{
    Solution solution;

    std::cout << solution.tribonacci(4) << "\n";
    std::cout << solution.tribonacci(25) << "\n";

    return 0;
}