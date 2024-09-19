/**
 * Problem:
 *  LeetCode 75 -> Sliding Window
 *  643. Maximum Average Subarray I (Easy)
 *  https://leetcode.com/problems/maximum-average-subarray-i/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/maximum-average-subarray-i/submissions/1387537751?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      135ms
 *      Beats: 20.56%
 *  Memory
 *      112.80MB
 *      Beats: 42.90%
 */

#include <iostream>
#include <cassert>

#include <vector>
#include <cfloat>

class Solution
{
public:
    double findMaxAverage(std::vector<int> &nums, int k)
    {
        std::size_t size = nums.size(),
                    i = 0;

        double max_avg = -DBL_MAX,
               avg;
        int sum = 0;

        for (std::size_t j = 0; j < k; ++j)
            sum += nums[j];

        do
        {
            if ((avg = static_cast<double>(sum) / k) > max_avg)
                max_avg = avg;

            sum -= nums[i];
            if (i + k < size)
                sum += nums[i + k];
        } while (++i <= size - k);

        return max_avg;
    }
};

int main()
{
    Solution solution;

    return 0;
}