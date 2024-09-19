/**
 * Problem:
 *  LeetCode 75 -> Array / String
 *  1431. Kids With the Greatest Number of Candies (Easy)
 *  https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/submissions/1141358825?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      0ms
 *      Beats: 100.00%
 *  Memory
 *      9.21MB
 *      Beats: 100.00%
 */

#include <cassert>

#include <vector>
#include <algorithm>
#include <cstdint>

class Solution
{
public:
    std::vector<bool> kidsWithCandies(const std::vector<int> &candies, int extraCandies)
    {
        uint8_t max = *std::max_element(candies.begin(), candies.end()),
                size = candies.size(),
                i = UINT8_MAX;
        std::vector<bool> result(size);

        while (++i < size)
            result[i] = (candies[i] + extraCandies >= max);

        return result;
    }
};

int main()
{
    Solution solution;

    assert(solution.kidsWithCandies({2, 3, 5, 1, 3}, 3) == std::vector({true, true, true, false, true}));
    assert(solution.kidsWithCandies({4, 2, 1, 1, 2}, 1) == std::vector({true, false, false, false, false}));
    assert(solution.kidsWithCandies({12, 1, 12}, 10) == std::vector({true, false, true}));

    return 0;
}