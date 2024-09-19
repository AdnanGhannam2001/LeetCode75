/**
 * Problem:
 *  LeetCode 75 -> Hash Map / Set
 *  1207. Unique Number of Occurrences (Easy)
 *  https://leetcode.com/problems/unique-number-of-occurrences/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/unique-number-of-occurrences/submissions/1364420680?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      0ms
 *      Beats: 100.00%
 *  Memory
 *      11.26MB
 *      Beats: 64.65%
 */

#include <iostream>
#include <cassert>

#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution
{
public:
    bool uniqueOccurrences(const std::vector<int>& arr)
    {
        std::unordered_map<int, uint16_t> freq_map;
        for (const auto &num : arr)
        {
            auto item = freq_map.find(num);
            if (item != freq_map.end())
                item->second++;
            else
                freq_map[num] = 1;
        }

        std::unordered_set<uint16_t> freq_set;
        for (const auto &[_, freq] : freq_map)
        {
            if (!freq_set.insert(freq).second)
                return false;
        }

        return true;
    }
};

int main()
{
    Solution solution;

    assert(solution.uniqueOccurrences(std::vector({1, 2, 2, 1, 1, 3})) == true);
    assert(solution.uniqueOccurrences(std::vector({1, 2})) == false);
    assert(solution.uniqueOccurrences(std::vector({-3, 0, 1, -3, 1, 1, 1, -3, 10, 0})) == true);
    assert(solution.uniqueOccurrences(std::vector({3,5,-2,-3,-6,-6})) == false);
    assert(solution.uniqueOccurrences(std::vector({1,2,2,1,1,3})) == true);
    assert(solution.uniqueOccurrences(std::vector({26,2,16,16,5,5,26,2,5,20,20,5,2,20,2,2,20,2,16,20,16,17,16,2,16,20,26,16})) == false);

    return 0;
}