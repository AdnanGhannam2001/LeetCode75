/**
 * Problem:
 *  LeetCode 75 -> DP - 1D
 *  198. House Robber (Medium)
 *  https://leetcode.com/problems/house-robber/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/house-robber/submissions/1386404479?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      0ms
 *      Beats: 100.00%
 *  Memory
 *      10.36MB
 *      Beats: 11.90%
 */

#include <iostream>
#include <cassert>

#include <vector>
#include <unordered_map>

class Solution
{
private:
    using Index = uint16_t;
    using Max = int;
    using Map = std::unordered_map<Index, Max>;

    int rob_impl(Index index, const std::vector<int> &nums, Map &map)
    {
        if (index >= nums.size())
            return 0;

        if (index == nums.size() - 1)
            return nums[index];
        
        if (map.count(index) > 0)
            return map[index];

        return (map[index] = nums[index] + std::max(rob_impl(index + 2, nums, map), rob_impl(index + 3, nums, map)));
    }

public:
    int rob(const std::vector<int> &nums)
    {
        Map map;
        return std::max(rob_impl(0, nums, map), rob_impl(1, nums, map));
    }
};

int main()
{
    Solution solution;
    std::cout << solution.rob({1, 2, 3, 1}) << "\n";
    std::cout << solution.rob({2, 7, 9, 3, 1}) << "\n";
    std::cout << solution.rob({2, 1, 1, 2}) << "\n";
    return 0;
}