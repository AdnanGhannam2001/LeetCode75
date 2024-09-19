/**
 * Problem:
 *  LeetCode 75 -> Two Pointers
 *  283. Move Zeroes (Easy)
 *  https://leetcode.com/problems/move-zeroes/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/move-zeroes/submissions/1387534493?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      21ms
 *      Beats: 18.98%
 *  Memory
 *      21.98MB
 *      Beats: 28.06%
 */

#include <iostream>
#include <cassert>

#include <vector>

class Solution
{
public:
    void moveZeroes(std::vector<int>& nums)
    {
        std::size_t i = nums.size();

        while (i > 0 && nums[--i] == 0)
            ;

        while (i >= 0)
        {
            if (nums[i] == 0)
            {
                nums.erase(nums.begin() + i);
                nums.emplace_back(0);
            }

            if (i-- == 0)
                break;
        }
    }
};

int main()
{
    Solution solution;

    {
        std::vector<int> vec = {1, 2, 3, 0, 0};
        solution.moveZeroes(vec);
    }
    {
        std::vector<int> vec = {0, 1, 0, 3, 12};
        solution.moveZeroes(vec);
    }
    {
        std::vector<int> vec = {0};
        solution.moveZeroes(vec);
    }
    {
        std::vector<int> vec = {0, 0, 1};
        solution.moveZeroes(vec);
    }

    return 0;
}