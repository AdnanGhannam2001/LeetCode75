/**
 * Problem:
 *  LeetCode 75 -> Array / String
 *  334. Increasing Triplet Subsequence (Medium)
 *  https://leetcode.com/problems/increasing-triplet-subsequence/description/?envType=study-plan-v2&envId=leetcode-75
 * 
 * Solution:
 *  https://leetcode.com/problems/increasing-triplet-subsequence/submissions/1387531715?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      114ms
 *      Beats: 5.80%
 *  Memory
 *      114.44MB
 *      Beats: 66.18%
 */

#include <iostream>
#include <cassert>

#include <vector>

class Solution
{
public:
    bool increasingTriplet(const std::vector<int>& nums)
    {
        std::size_t size = nums.size(),
                    i = 0,
                    j = 0,
                    k = 0;

        if (size < 3)
            return false;

        while (i < size - 2)
        {
            // SKIPPING
            {
                bool repeat = true;
                int el1 = nums[i],
                    el2 = nums[i + 1];

                for (std::size_t x = i + 3; x < size; x += 2)
                {
                    if (!(repeat = repeat && el1 == nums[x - 1] && el2 == nums[x]))
                        break;

                    el1 = nums[x - 1],
                    el2 = nums[x],
                    i = x - 2;
                }
            }

            j = ++i;
            while (j++ < size - 1)
            {
                if (nums[i - 1] >= nums[j - 1])
                    continue;

                k = j;
                while (k++ < size)
                    if (nums[j - 1] < nums[k - 1])
                        return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution solution;

    assert(solution.increasingTriplet(std::vector({1, 2, 3, 4, 5})) == true);
    assert(solution.increasingTriplet(std::vector({5, 4, 3, 2, 1})) == false);
    assert(solution.increasingTriplet(std::vector({2, 1, 5, 0, 4, 6})) == true);
    assert(solution.increasingTriplet(std::vector({1, 5, 0, 4, 1, 3})) == true);
    assert(solution.increasingTriplet(std::vector({0, 4, 2, 1, 0, -1, -3})) == false);
    assert(solution.increasingTriplet(std::vector({1, 2, 2, 1})) == false);
    assert(solution.increasingTriplet(std::vector({1, 2, -10, -8, -7})) == true);
    assert(solution.increasingTriplet(std::vector({20, 100, 10, 12, 5, 13})) == true);
    assert(solution.increasingTriplet(std::vector({1})) == false);
    assert(solution.increasingTriplet(std::vector({2, 4, -2, -3})) == false);
    assert(solution.increasingTriplet(std::vector({4, 5, 2147483647, 1, 2})) == true);
    assert(solution.increasingTriplet(std::vector({1, 6, 2, 5, 1})) == true);
    assert(solution.increasingTriplet(std::vector({1, 2, 1, 3})) == true);

    return 0;
}
