/**
 * Problem:
 *  LeetCode 75 -> Sliding Window
 *  1456. Maximum Number of Vowels in a Substring of Given Length (Medium)
 *  https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/submissions/1387541923?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      14ms
 *      Beats: 94.47%
 *  Memory
 *      10.72MB
 *      Beats: 99.63%
 */

#include <iostream>
#include <cassert>

#include <string>

class Solution
{
private:
    constexpr bool is_volwel(const char& c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int maxVowels(const std::string& s, const int k)
    {
        std::size_t length = s.length(),
                    i = 0;
        
        int max_freq = 0,
            curr_freq = 0;

        for (int j = 0; j < k; ++j)
            if (is_volwel(s[j]))
                max_freq += 1;

        curr_freq = max_freq;
        while (++i <= length - k)
        {
            if (is_volwel(s[i - 1]))
                curr_freq--;
            if (is_volwel(s[i + k - 1]))
                curr_freq++;

            max_freq = max_freq > curr_freq ? max_freq: curr_freq;
        }
        
        return max_freq;
    }
};

int main()
{
    Solution solution;

    assert(solution.maxVowels("abciiidef", 3) == 3);
    assert(solution.maxVowels("aeiou", 2) == 2);
    assert(solution.maxVowels("weallloveyou", 7) == 4);
    
    return 0;
}