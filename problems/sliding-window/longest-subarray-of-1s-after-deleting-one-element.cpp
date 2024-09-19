/**
 * Problem:
 *  LeetCode 75 -> Sliding Window
 *  1493. Longest Subarray of 1's After Deleting One Element (Medium)
 *  https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/submissions/1387543668?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      39ms
 *      Beats: 73.40%
 *  Memory
 *      58.90MB
 *      Beats: 56.31%
 */

#include <iostream>
#include <cassert>

#include <vector>

class Solution
{
public:
    int longestSubarray(const std::vector<int>& nums)
    {
        std::size_t size = nums.size(),
                    i = 0,
                    j = 0,
                    max_sequ = 0;

        int zero = -2;

        do
        {
            if (nums[j] == 0)
                if (zero < 0)
                    zero = j;
                else
                    max_sequ = max_sequ > j - i - 1 ? max_sequ : j - i - 1,
                    i = zero + 1,
                    zero = j;
        } while (++j < size);

        max_sequ = max_sequ > j - i - 1 ? max_sequ : j - i - 1;

        return zero == -2 ? size - 1 : max_sequ;
    }
};

int main()
{
    Solution solution;

    assert(solution.longestSubarray(std::vector({1, 1, 0, 1})) == 3);
    assert(solution.longestSubarray(std::vector({0, 1, 1, 1, 0, 1, 1, 0, 1})) == 5);
    assert(solution.longestSubarray(std::vector({1, 1, 1})) == 2);
    assert(solution.longestSubarray(std::vector({1, 1, 1, 1})) == 3);
    assert(solution.longestSubarray(std::vector({1, 1, 1, 1, 0})) == 4);
    assert(solution.longestSubarray(std::vector({1})) == 0);
    assert(solution.longestSubarray(
               std::vector({1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1})) == 14);

    return 0;
}