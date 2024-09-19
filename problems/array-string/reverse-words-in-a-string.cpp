/**
 * Problem:
 *  LeetCode 75 -> Array / String
 *  151. Reverse Words in a String (Medium)
 *  https://leetcode.com/problems/reverse-words-in-a-string/submissions/1142354513/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/reverse-words-in-a-string/submissions/1142354513?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      0ms
 *      Beats: 100.00%
 *  Memory
 *      7.52MB
 *      Beats: 100.00%
 */

#include <cassert>

#include <string>

class Solution {
public:
    std::string reverseWords(const std::string &s) {
        int16_t end = -1,
                size = s.length(), i = size;

        std::string rs = "";

        while (--i >= 0) {
            if (s[i] != ' ' && end == -1) {
                end = i;
            } else if (s[i] == ' ' && end != -1) {
                rs += s.substr(i + 1, end - i) + " ";
                end = -1;
            }
        }
        if (end != -1) {
            rs += s.substr(0, end - i) + " ";
        }

        if (rs.back() == ' ') { rs.pop_back(); }

        return rs;
    }
};

int main()
{
    Solution solution;

    assert(solution.reverseWords("the sky is blue") == "blue is sky the");
    assert(solution.reverseWords("  hello world  ") == "world hello");
    assert(solution.reverseWords("a good   example") == "example good a");

    return 0;
}