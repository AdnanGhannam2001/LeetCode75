/**
 * Problem:
 *  LeetCode 75 -> Binary Search
 *  162. Find Peak Element (Medium)
 *  https://leetcode.com/problems/find-peak-element/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/find-peak-element/submissions/1383161678?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      0ms
 *      Beats: 100.00%
 *  Memory
 *      11.52MB
 *      Beats: 66.52%
 */

#include <iostream>
#include <cassert>

#include <vector>

class Solution
{
public:
    int findPeakElement(const std::vector<int> &nums)
    {
        uint16_t size = nums.size();

        if (size == 1)
            return 0;

        for (uint16_t i = 0; i < size; ++i)
        {
            if ((i <= 0 || nums[i - 1] < nums[i]) && (i >= size - 1 || nums[i] > nums[i + 1]))
                return i;

            if (i < size - 1 && nums[i] >= nums[i + 1])
                i++;
        }

        return -1; // UNREACHABLE
    }
};

int main()
{
    return 0;
}