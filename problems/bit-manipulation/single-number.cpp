/**
 * Problem:
 *  LeetCode 75 -> Bit Manipulation
 *  338. Counting Bits (Easy)
 *  https://leetcode.com/problems/single-number/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/single-number/submissions/1366794138?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      15ms
 *      Beats: 52.60%
 *  Memory
 *      19.60MB
 *      Beats: 28.70%
 */

#include <iostream>
#include <cassert>

#include <vector>

class Solution
{
public:
    int singleNumber(const std::vector<int> &nums)
    {
        int result = 0;

        for (const auto& num : nums)
        {
            result ^= num;
        }

        return result;
    }
};

int main()
{
    Solution solution;



    return 0;
}