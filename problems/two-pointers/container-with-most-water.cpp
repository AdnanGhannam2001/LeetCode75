/**
 * Problem:
 *  LeetCode 75 -> Two Pointers
 *  11. Container With Most Water (Medium)
 *  https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/container-with-most-water/submissions/1387536732?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      60ms
 *      Beats: 62.95%
 *  Memory
 *      61.73MB
 *      Beats: 26.65%
 */

#include <iostream>
#include <cassert>

#include <vector>

class Solution
{
public:
    int maxArea(const std::vector<int>& height)
    {
        std::size_t i = 0,
                    j = height.size() - 1;

        int max_area = 0;
        int curr_area;

        while (i < j)
        {
            int min_value = std::min(height[i], height[j]);
            if ((curr_area = min_value * (j - i)) > max_area)
                max_area = curr_area;

            if (min_value == height[i])
                i++;
            else
                j--;
        }

        return max_area;
    }
};

int main()
{
    Solution solution;

    assert(solution.maxArea(std::vector({1, 8, 6, 2, 5, 4, 8, 3, 7})) == 49);
    assert(solution.maxArea(std::vector({1, 1})) == 1);
    assert(solution.maxArea(std::vector({1, 2, 1})) == 2);
    assert(solution.maxArea(std::vector({1, 2, 4, 3})) == 4);
    assert(solution.maxArea(std::vector({2, 3, 4, 5, 18, 17, 6})) == 17);

    return 0;
}