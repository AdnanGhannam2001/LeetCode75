/**
 * Problem:
 *  LeetCode 75 -> Prefix Sum
 *  724. Find Pivot Index (Easy)
 *  https://leetcode.com/problems/find-pivot-index/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/find-pivot-index/submissions/1387544957?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      7ms
 *      Beats: 98.83%
 *  Memory
 *      34.70MB
 *      Beats: 70.61%
 */

#include <iostream>
#include <cassert>

#include <vector>

class Solution
{
public:
    int pivotIndex(const std::vector<int> &nums)
    {
        std::size_t size = nums.size(),
                    i;

        int lmax = 0,
            rmax = 0;

        for (i = 1; i < size; ++i)
            rmax += nums[i];

        if (lmax == rmax)
            return 0;

        for (i = 1; i < size; ++i)
        {
            lmax += nums[i - 1];
            rmax -= nums[i];

            if (lmax == rmax)
                return i;
        }

        return -1;
    }
};

int main()
{
    Solution solution;

    assert(solution.pivotIndex(std::vector<int>({1, 7, 3, 6, 5, 6})) == 3);

    return 0;
}