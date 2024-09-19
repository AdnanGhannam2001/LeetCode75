/**
 * Problem:
 *  LeetCode 75 -> Array / String
 *  238. Product of Array Except Self (Medium)
 *  https://leetcode.com/problems/reverse-words-in-a-string/submissions/1142354513/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/product-of-array-except-self/submissions/1387530753?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      31ms
 *      Beats: 32.15%
 *  Memory
 *      38.33MB
 *      Beats: 85.84%
 */

#include <cassert>

#include <vector>
#include <cstdint>
#include <cstring>

class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        unsigned int size = nums.size();
        int mult = 1;

        int zero_index = -1;
        bool zeros = false;

        for (unsigned int i = 0; i < size; ++i)
        {
            if (nums[i] == 0)
            {
                if (zero_index != -1)
                {
                    zeros = true;
                    break;
                }

                zero_index = i;
            }
            else
                mult *= nums[i];
        }

        if (zero_index == -1)
            for (unsigned int i = 0; i < size; ++i)
                nums[i] = mult / nums[i];
        else
        {
            memset(nums.data(), 0, nums.size() * sizeof(int));
            if (!zeros)
                nums[zero_index] = mult;
        }

        return nums;
    }
};

int main()
{
    Solution solution;

    {
        std::vector vec = {1, 2, 3, 4};
        assert(solution.productExceptSelf(vec) == std::vector({24, 12, 8, 6}));
    }
    {
        std::vector vec = {-1, 1, 0, -3, 3};
        assert(solution.productExceptSelf(vec) == std::vector({0, 0, 9, 0, 0}));
    }

    return 0;
}