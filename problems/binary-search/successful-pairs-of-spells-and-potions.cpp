/**
 * Problem:
 *  LeetCode 75 -> Binary Search
 *  2300. Successful Pairs of Spells and Potions (Medium)
 *  https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/successful-pairs-of-spells-and-potions/submissions/1383095878?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      160ms
 *      Beats: 19.52%
 *  Memory
 *      100.94MB
 *      Beats: 85.67%
 */

#include <iostream>
#include <cassert>

#include <algorithm>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> successfulPairs(const std::vector<int> &spells, std::vector<int> &potions, long long success)
    {
        std::size_t ssize = spells.size(),
                    psize = potions.size();

        std::vector<int> results(ssize, 0);

        std::sort(potions.begin(), potions.end());

        for (std::size_t i = 0; i < ssize; ++i)
        {
            int distance = std::distance(potions.begin(),
                                         std::lower_bound(
                                             potions.begin(), potions.end(),
                                             success,
                                             [&spells, i](const int current, long long value)
                                             {
                                                 return (long long)current * spells[i] < value;
                                             }));

            if (distance >= psize)
                results[i] = 0;
            else
                results[i] = psize - distance;
        }

        return results;
    }
};

int main()
{
    Solution solution;

    std::vector<int> potions = {1, 2, 3, 4, 3, 5};
    solution.successfulPairs(std::vector({5, 1, 3}), potions, 7);

    return 0;
}
