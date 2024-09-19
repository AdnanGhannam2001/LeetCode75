/**
 * Problem:
 *  LeetCode 75 -> Binary Search
 *  374. Guess Number Higher or Lower (Medium)
 *  https://leetcode.com/problems/guess-number-higher-or-lower/submissions/1382844174/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/guess-number-higher-or-lower/submissions/1382844174?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      2059ms
 *      Beats: 14.44%
 *  Memory
 *      7.62MB
 *      Beats: 16.05%
 */

#include <iostream>
#include <cassert>

extern int guess(int num);

class Solution
{
public:
    int guessNumber(int n)
    {
        int g = guess(n);
        if (g == 0)
            return n;

        return g > 0
                   ? guessNumber(n + 1)
                   : guessNumber(n - 1);
    }
};

int main()
{
    return 0;
}