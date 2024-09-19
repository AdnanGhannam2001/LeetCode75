/**
 * Problem:
 *  LeetCode 75 -> Array / String
 *  1071. Greatest Common Divisor of Strings (Easy)
 *  https://leetcode.com/problems/greatest-common-divisor-of-strings/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/greatest-common-divisor-of-strings/submissions/1360645747?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      0ms
 *      Beats: 100.00%
 *  Memory
 *      8.34MB
 *      Beats: 96.70%
 */

#include <iostream>
#include <cassert>

#include <string>
#include <string_view>

class Solution
{
public:
    std::string gcdOfStrings(const std::string &str1, const std::string &str2)
    {
        const int len1 = str1.length();
        const int len2 = str2.length();

        const int max_len = len1 > len2 ? len1 : len2;
        const int min_len = len1 < len2 ? len1 : len2;
        int len = len1 < len2 ? len1 : len2;

        const std::string_view max(len1 >= len2 ? str1 : str2);
        const std::string_view min(len1 < len2 ? str1 : str2);
        std::string_view sv(len1 < len2 ? str1 : str2);

        while ((len = sv.length()))
        {
            if (max_len % len == 0 && min_len % len == 0)
            {
                bool accepted = false;

                {
                    uint16_t max_iter = max_len / len;
                    for (uint16_t i = 0; i < max_iter && (accepted = max.substr(i * len, len) == sv); ++i)
                        ;
                }

                {
                    uint16_t max_iter = min_len / len;
                    for (uint16_t i = 0; accepted && i < max_iter && (accepted = min.substr(i * len, len) == sv); ++i)
                        ;
                }

                if (accepted)
                {
                    return std::string(sv);
                }
            }

            sv = sv.substr(0, sv.length() - 1);
        }

        return "";
    }
};

int main()
{
    Solution solution;

    assert(solution.gcdOfStrings("ABCABC", "ABC") == "ABC");
    assert(solution.gcdOfStrings("ABABAB", "ABAB") == "AB");
    assert(solution.gcdOfStrings("LEET", "CODE") == "");
    assert(solution.gcdOfStrings("ABCDEF", "ABC") == "");
    assert(solution.gcdOfStrings("AAAAAA", "AA") == "AA");
    assert(solution.gcdOfStrings("ABABABAB", "ABAB") == "ABAB");
    assert(solution.gcdOfStrings("XYZXYZXYZ", "XYZ") == "XYZ");
    assert(solution.gcdOfStrings("A", "A") == "A");
    assert(solution.gcdOfStrings("A", "B") == "");
    assert(solution.gcdOfStrings("", "") == "");
    assert(solution.gcdOfStrings("A", "") == "");
    assert(solution.gcdOfStrings("TAUXXTAUXXTAUXXTAUXXTAUXX", "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX") == "TAUXX");

    return 0;
}