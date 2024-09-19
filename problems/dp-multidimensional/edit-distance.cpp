/**
 * Problem:
 *  LeetCode 75 -> DP - Multidimensional
 *  72. Edit Distance (Medium)
 *  https://leetcode.com/problems/edit-distance/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *
 *  Runtime
 *      2ms
 *      Beats: 53.58%
 *  Memory
 *      7.26MB
 *      Beats: 98.55%
 */

#include <iostream>
#include <cassert>

#include <string>
#include <cstring>

class Solution
{
public:
    int minDistance(std::string &word1, std::string &word2)
    {
        word1.insert(word1.begin(), ' ');
        word2.insert(word2.begin(), ' ');

        uint16_t rows = word1.length(),
                 cols = word2.length(),
                 x, y,
                 acc = 0;

        uint16_t matrix[rows][cols];
        matrix[0][0] = 0;

        for (y = 0; y < rows; ++y)
            for (x = 0; x < cols; ++x)
                if (x == 0 && y == 0)
                    continue;
                else if (word1[y] == word2[x])
                    matrix[y][x] = matrix[y - 1][x - 1];
                else
                    matrix[y][x] = 1 + std::min(
                                           std::min(
                                               (y > 0 ? matrix[y - 1][x] : uint16_t(UINT16_MAX)),
                                               (x > 0 ? matrix[y][x - 1] : uint16_t(UINT16_MAX))),
                                           (x > 0 && y > 0 ? matrix[y - 1][x - 1] : uint16_t(UINT16_MAX)));

        return matrix[rows - 1][cols - 1];
    }
};

int main()
{
    Solution solution;

    return 0;
}