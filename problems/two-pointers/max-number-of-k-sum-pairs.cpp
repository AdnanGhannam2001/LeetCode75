/**
 * Problem:
 *  LeetCode 75 -> Two Pointers
 *  1679. Max Number of K-Sum Pairs (Medium)
 *  https://leetcode.com/problems/max-number-of-k-sum-pairs/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/max-number-of-k-sum-pairs/submissions/1387539869?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      155ms
 *      Beats: 9.92%
 *  Memory
 *      89.56MB
 *      Beats: 5.14%
 */

#include <iostream>
#include <cassert>

#include <vector>
#include <unordered_map>

class Solution
{
public:
    int maxOperations(std::vector<int> &nums, int k)
    {
        std::size_t size = nums.size(),
                    count = 0;

        std::unordered_map<int, int> freq_map;

        for (const auto &num : nums)
            if (!freq_map.insert({num, 1}).second)
                freq_map[num]++;

        for (auto& [num, freq] : freq_map)
        {
            auto addend = freq_map.find(k - num);

            if (addend != freq_map.end() && addend->second != 0)
            {
                if (num != addend->first)
                {
                    int mn = std::min(freq, addend->second);
                    freq -= mn;
                    addend->second -= mn;
                    count += mn;
                }
                else
                {
                    count += freq / 2;
                    freq = freq % 2;
                }
            }
        }

        return count;
    }
};

int main()
{
    Solution solution;

    {
        std::vector vec = {1, 2, 3, 4};
        assert(solution.maxOperations(vec, 5) == 2);
    }
    {
        std::vector vec = {3, 1, 3, 4, 3, 3, 3};
        assert(solution.maxOperations(vec, 6) == 2);
    }
    {
        std::vector vec = {2, 2, 2, 3, 1, 1, 4, 1};
        assert(solution.maxOperations(vec, 4) == 2);
    }
    {
        std::vector vec = {1, 1, 2, 4, 4};
        assert(solution.maxOperations(vec, 5) == 2);
    }
    {
        std::vector vec = {29,26,81,70,75,4,48,38,22,10,51,62,17,50,7,7,24,61,54,44,30,29,66,83,6,45,24,49,42,31,10,6,88,48,34,10,54,56,80,41,19};
        assert(solution.maxOperations(vec, 12) == 1);
    }

    return 0;
}