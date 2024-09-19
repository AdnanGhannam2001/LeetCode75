/**
 * Problem:
 *  LeetCode 75 -> Hash Map / Set
 *  2352. Equal Row and Column Pairs (Medium)
 *  https://leetcode.com/problems/equal-row-and-column-pairs/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/equal-row-and-column-pairs/submissions/1387547887?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      171ms
 *      Beats: 9.38%
 *  Memory
 *      26.34MB
 *      Beats: 97.46%
 */

#include <iostream>
#include <cassert>

#include <vector>

class Solution
{
public:
    int equalPairs(const std::vector<std::vector<int>> &grid)
    {
        std::size_t size = grid.size(),
                    i, j, k,
                    acc = 0;

        for (i = 0; i < size; ++i)
        {
            for (j = 0; j < size; ++j)
            {
                bool equals = false;
                for (k = 0; k < size; ++k)
                {
                    if (grid[k][j] != grid[i][k])
                        break;
                    if (k == size - 1)
                        equals = true;
                }

                if (equals)
                    acc++;
            }
        }

        return acc;
    }
};

int main()
{
    Solution solution;

    assert(solution.equalPairs(std::vector(
               {std::vector({3, 2, 1}),
                std::vector({1, 7, 6}),
                std::vector({2, 7, 7})})) == 1);
    assert(solution.equalPairs(std::vector(
               {std::vector({3, 1, 2, 2}),
                std::vector({1, 4, 4, 5}),
                std::vector({2, 4, 2, 2}),
                std::vector({2, 4, 2, 2})})) == 3);

    return 0;
}