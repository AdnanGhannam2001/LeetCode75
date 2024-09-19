/**
 * Problem:
 *  LeetCode 75 -> Stack
 *  394. Decode String (Medium)
 *  https://leetcode.com/problems/decode-string/submissions/1365420798/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/decode-string/submissions/1387551861?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      0ms
 *      Beats: 100.00%
 *  Memory
 *      8.16MB
 *      Beats: 53.27%
 */

#include <iostream>
#include <cassert>

#include <string>

class Solution
{
private:
    static constexpr bool is_digit(const char c)
    {
        return c >= '0' && c <= '9';
    }

    static constexpr bool is_alpha(const char c)
    {
        return c >= 'a' && c <= 'z';
    }

    std::string parse(const std::string &s, uint16_t &current)
    {
        if (is_digit(s[current]))
        {
            uint16_t start = current;
            while (is_digit(s[current++]))
                ;

            uint16_t length = std::stoi(s.substr(start, current - start - 1));

            std::string seq;
            while (s[current] != ']')
                seq += parse(s, current);

            std::string result;
            for (uint16_t i = 0; i < length; ++i)
                result += seq;

            current++;

            return result;
        }
        else if (is_alpha(s[current]))
        {
            uint16_t start = current;
            while (is_alpha(s[current]))
                current++;

            return s.substr(start, current - start);
        }

        return "";
    }

public:
    std::string decodeString(const std::string &s)
    {
        uint16_t i = 0;
        std::string result;
        do
        {
            result += parse(s, i);
        } while (i < s.length());
        
        return result;
    }
};

int main()
{
    Solution solution;

    assert(solution.decodeString("a3[a]2[bc]") == "aaaabcbc");
    assert(solution.decodeString("3[a]2[bc]") == "aaabcbc");
    assert(solution.decodeString("3[a2[c]]") == "accaccacc");
    assert(solution.decodeString("2[abc]3[cd]ef") == "abcabccdcdcdef");
    assert(solution.decodeString("5[5[5[5[a]a2[b]c4[j]]]]") == "aaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjjaaaaaabbcjjjj");

    return 0;
}