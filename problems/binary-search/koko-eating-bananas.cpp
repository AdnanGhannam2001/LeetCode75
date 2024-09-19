/**
 * Problem:
 *  LeetCode 75 -> Binary Search
 *  875. Koko Eating Bananas (Medium)
 *  https://leetcode.com/problems/koko-eating-bananas/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/koko-eating-bananas/submissions/1386930951?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      28ms
 *      Beats: 76.52%
 *  Memory
 *      21.75MB
 *      Beats: 49.68%
 * 
 * Notes:
 *  - This problem was solved with the help of this article
 *      https://leetcode.com/discuss/interview-question/3725477/binary-search-on-answer-koko-type
 */

#include <iostream>
#include <cassert>

#include <vector>
#include <algorithm>

class Solution
{
private:
    using Pile = int;
    using Piles = std::vector<Pile>;
    using PilesCIter = Piles::const_iterator;

public:
    int minEatingSpeed(const Piles &piles, int h)
    {
        uint32_t start = 1,
                 end = *std::max_element(piles.begin(), piles.end()),
                 curr = start + (end - start) / 2,
                 res = 0,
                 k = 0;

        PilesCIter citer;

        while (start <= end)
        {
            for (k = 0,
                citer = piles.begin(),
                curr = start + (end - start) / 2;
                 citer != piles.end();
                 ++citer)
                k += *citer / curr + (*citer % curr != 0 ? 1 : 0);

            if (k <= h)
                res = std::min(end, curr),
                end = curr - 1;
            else
                start = curr + 1;
        }

        return res;
    }
};

int main()
{
    Solution solution;

    std::cout << solution.minEatingSpeed({3, 6, 7, 11}, 8) << "\n";
    std::cout << solution.minEatingSpeed({30, 11, 23, 4, 20}, 5) << "\n";
    std::cout << solution.minEatingSpeed({30, 11, 23, 4, 20}, 6) << "\n";
    std::cout << solution.minEatingSpeed({805306368, 805306368, 805306368}, 1000000000) << "\n";
    std::cout << solution.minEatingSpeed({1000000000}, 2) << "\n";

    return 0;
}