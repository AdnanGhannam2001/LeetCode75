/**
 * Problem:
 *  LeetCode 75 -> Bit Manipulation
 *  1318. Minimum Flips to Make a OR b Equal to c (Medium)
 *  https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/submissions/1367387933?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      2ms
 *      Beats: 52.57%
 *  Memory
 *      7.45MB
 *      Beats: 39.70%
 */

#include <iostream>
#include <cassert>

class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        std::size_t flips = 0;

        do
        {
            if ((((a & 1) | (b & 1)) != (c & 1)) && ++flips)
                if ((a & 1) & (b & 1))
                    flips++;
        } while ((a >>= 1) + (b >>= 1) + (c >>= 1));

        return flips;
    }
};

int main()
{
    Solution solution;

    assert(solution.minFlips(2, 6, 5) == 3);
    assert(solution.minFlips(4, 2, 7) == 1);
    assert(solution.minFlips(1, 2, 3) == 0);
    assert(solution.minFlips(7, 3, 9) == 4);
    assert(solution.minFlips(58076, 49567, 394506) == 17);

    return 0;
}