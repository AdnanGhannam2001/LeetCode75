/**
 * Problem:
 *  LeetCode 75 -> Array / String
 *  1768. Merge Strings Alternately (Easy)
 *  https://leetcode.com/problems/merge-strings-alternately/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/merge-strings-alternately/submissions/1141339314?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      0ms
 *      Beats: 100.00%
 *  Memory
 *      6.66MB
 *      Beats: 100.00%
 */

#include <cassert>

#include <string>

class Solution
{
public:
    std::string mergeAlternately(const std::string &word1, const std::string &word2)
    {
        uint8_t l1 = word1.length(), l2 = word2.length(),
                i = 0;

        std::string s = "";

        while (i < l1 || i < l2)
        {
            if (i < l1)
                s += word1[i];
            if (i < l2)
                s += word2[i];
            i++;
        }

        return s;
    }
};

int main()
{
    Solution solution;

    assert(solution.mergeAlternately("abc", "pqr") == "apbqcr");
    assert(solution.mergeAlternately("ab", "pqrs") == "apbqrs");
    assert(solution.mergeAlternately("abcd", "pq") == "apbqcd");

    return 0;
}