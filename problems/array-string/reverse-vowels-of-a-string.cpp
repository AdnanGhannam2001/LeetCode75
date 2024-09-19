/**
 * Problem:
 *  LeetCode 75 -> Array / String
 *  345. Reverse Vowels of a String (Easy)
 *  https://leetcode.com/problems/reverse-vowels-of-a-string/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/reverse-vowels-of-a-string/submissions/1387526772?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      3ms
 *      Beats: 96.26%
 *  Memory
 *      9.34MB
 *      Beats: 78.89%
 */

#include <cassert>

#include <string>
#include <cstdint>

#define IS_VOWEL_EXPRESSION(c) (c == 'a' \
    || c == 'e' \
    || c == 'i' \
    || c == 'o' \
    || c == 'u' \
    || c == 'A' \
    || c == 'E' \
    || c == 'I' \
    || c == 'O' \
    || c == 'U')

class Solution {
public:
    std::string reverseVowels(std::string& s)
    {
        uint32_t i = 0,
                 j = s.length() - 1;
            
        while (i < j)
        {
            if (IS_VOWEL_EXPRESSION(s[i]) && IS_VOWEL_EXPRESSION(s[j]))
            {
                std::swap(s[i], s[j]);
                i++, j--;
            }
            else if (!IS_VOWEL_EXPRESSION(s[i]))
                i++;
            else if (!IS_VOWEL_EXPRESSION(s[j]))
                j--;
        }

        return s;
    }
};



int main()
{
    Solution solution;

    return 0;
}