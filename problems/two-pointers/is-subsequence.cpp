/**
 * Problem:
 *  LeetCode 75 -> Two Pointers
 *  392. Is Subsequence (Easy)
 *  https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/is-subsequence/submissions/1387535140?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      0ms
 *      Beats: 100.00%
 *  Memory
 *      7.55MB
 *      Beats: 98.81%
 */

#include <iostream>
#include <cassert>

#include <string>
#include <cstdint>

class Solution
{
public:
    bool isSubsequence(const std::string& s, const std::string& t)
    {
        uint8_t i = 0,
                ss = s.size();

        std::size_t j = 0,
                    st = t.size();

        while (i < ss && j < st)
            if (s[i] == t[j++])
                i++;

        return i == ss;
    }
};

int main()
{
    Solution solution;

    assert(solution.isSubsequence("abc", "ahbgdc") == true);
    assert(solution.isSubsequence("axc", "ahbgdc") == false);
    assert(solution.isSubsequence("leeeeeetcode", "leeeeeeetcodee") == true);

    return 0;
}