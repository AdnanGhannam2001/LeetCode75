/**
 * Problem:
 *  LeetCode 75 -> Hash Map / Set
 *  2215. Find the Difference of Two Arrays (Easy)
 *  https://leetcode.com/problems/find-the-difference-of-two-arrays/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/find-the-difference-of-two-arrays/submissions/1387545918?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      34ms
 *      Beats: 79.20%
 *  Memory
 *      35.17MB
 *      Beats: 85.02%
 */

#include <iostream>
#include <cassert>

#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<std::vector<int>> findDifference(const std::vector<int>& nums1, const std::vector<int>& nums2)
    {
        std::vector<std::vector<int>> results(2, std::vector<int>());

        std::size_t size1 = nums1.size(),
                    size2 = nums2.size(),
                    max_size = size1 > size2 ? size1 : size2;

        std::unordered_map<int, uint8_t> occur;

        for (std::size_t i = 0; i < max_size; ++i)
        {
            if (i < size1)
            {
                auto item1 = occur.find(nums1[i]);
                if (item1 != occur.end())
                    item1->second = item1->second | 1;
                else
                    occur.insert({nums1[i], 1});
            }

            if (i < size2)
            {
                auto item2 = occur.find(nums2[i]);
                if (item2 != occur.end())
                    item2->second = item2->second | 2;
                else
                    occur.insert({nums2[i], 2});
            }
        }

        for (auto const &[num, o] : occur)
            if (o != 3)
                results[o - 1].push_back(num);

        return results;
    }
};

int main()
{
    Solution solution;

    solution.findDifference(std::vector({-68,-80,-19,-94,82,21,-43}), std::vector({-63}));

    return 0;
}