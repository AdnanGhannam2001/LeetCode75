/**
 * Problem:
 *  LeetCode 75 -> Sliding Window
 *  1004. Max Consecutive Ones III (Medium)
 *  https://leetcode.com/problems/max-consecutive-ones-iii/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/max-consecutive-ones-iii/submissions/1387542881?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      95ms
 *      Beats: 5.00%
 *  Memory
 *      87.90MB
 *      Beats: 5.15%
 */

#include <iostream>
#include <cassert>

#include <vector>
#include <list>

class Solution
{
public:
    int longestOnes(const std::vector<int>& nums, int k)
    {
        std::size_t size = nums.size(),
                    i = 0,
                    n = k,
                    max_occur = 0;

        std::list<bool> acc;

        while (i < size)
        {
            if (nums[i] == 1)
                acc.push_back(true);
            else if (nums[i] == 0 && n > 0)
            {
                acc.push_back(false);
                n--;
            }
            else
            {
                std::size_t acc_size = acc.size();
                max_occur = max_occur > acc_size ? max_occur : acc_size;
                if (!acc.empty() && acc.front() == false)
                {
                    n++;
                    acc.pop_front();
                    continue;
                }
                else
                {
                    while (!acc.empty())
                    {
                        if (acc.front() == false)
                        {
                            acc.pop_front();
                            acc.push_back(false);
                            break;
                        }

                        acc.pop_front();
                    }
                }
            }

            i++;
        }

        std::size_t acc_size = acc.size();
        max_occur = max_occur > acc_size ? max_occur : acc_size;

        return max_occur;
    }
};

int main()
{
    Solution solution;

    assert(solution.longestOnes(std::vector({1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}), 2) == 6);
    assert(solution.longestOnes(std::vector({0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1}), 3) == 10);
    assert(solution.longestOnes(std::vector({0, 0, 0, 1}), 4) == 4);
    assert(solution.longestOnes(std::vector({0, 0, 1, 1, 1, 0, 0}), 0) == 3);

    return 0;
}