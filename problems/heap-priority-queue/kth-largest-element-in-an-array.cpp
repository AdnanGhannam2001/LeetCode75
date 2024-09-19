/**
 * Problem:
 *  LeetCode 75 -> Heap / Priority Queue
 *  215. Kth Largest Element in an Array (Medium)
 *  https://leetcode.com/problems/kth-largest-element-in-an-array/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/1382085861?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      97ms
 *      Beats: 52.40%
 *  Memory
 *      59.08MB
 *      Beats: 85.33%
 */

#include <iostream>
#include <cassert>

#include <algorithm>
#include <vector>

class Solution
{
public:
    int findKthLargest(std::vector<int> &nums, int k)
    {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

int main()
{
    return 0;
}