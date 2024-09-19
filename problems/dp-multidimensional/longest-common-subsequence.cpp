/**
 * Problem:
 *  LeetCode 75 -> DP - Multidimensional
 *  1143. Longest Common Subsequence (Medium)
 *  https://leetcode.com/problems/longest-common-subsequence/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/longest-common-subsequence/submissions/1387376298?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      10ms
 *      Beats: 99.38%
 *  Memory
 *      9.83MB
 *      Beats: 89.79%
 */

#include <iostream>
#include <cassert>

#include <string>
#include <cstring>

class Solution
{
public:
    int longestCommonSubsequence(const std::string &text1, const std::string &text2)
    {
        uint16_t rows = text1.length() + 1,
                 cols = text2.length() + 1,
                 x, y,
                 acc = 0;

        uint16_t matrix[rows][cols];
        memset(matrix, 0, sizeof(uint16_t) * rows * cols);

        for (y = 1; y < rows; ++y)
            for (x = 1; x < cols; ++x)
                if (text1[y - 1] == text2[x - 1])
                    matrix[y][x] = matrix[y - 1][x - 1] + 1;
                else
                    matrix[y][x] = std::max(matrix[y - 1][x], matrix[y][x - 1]);

        for (y = rows - 1, x = cols - 1; y > 0 && x > 0;)
            if (matrix[y][x] > std::max(matrix[y - 1][x], matrix[y][x - 1]))
                y--, x--, acc++;
            else if (matrix[y][x - 1] > matrix[y - 1][x])
                x--;
            else
                y--;

        return acc;
    }
};

int main()
{
    Solution solution;

    assert(solution.longestCommonSubsequence("abcdef", "ace") == 3);
    assert(solution.longestCommonSubsequence("abc", "abc") == 3);
    assert(solution.longestCommonSubsequence("abc", "def") == 0);

    return 0;
}