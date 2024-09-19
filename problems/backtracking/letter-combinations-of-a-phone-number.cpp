/**
 * Problem:
 *  LeetCode 75 -> Backtracking
 *  17. Letter Combinations of a Phone Number (Medium)
 *  https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/1385429792?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      3ms
 *      Beats: 38.27%
 *  Memory
 *      7.77MB
 *      Beats: 99.98%
 */

#include <iostream>
#include <cassert>

#include <vector>
#include <string>
#include <cstring>

static const char *letters[] =
    {
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
};

class Solution
{
public:
    std::vector<std::string> letterCombinations(const std::string &digits)
    {
        uint8_t size = digits.size();
        int8_t i = 0, j = 0;

        if (size == 0)
            return {};

        std::vector<std::string> results;

        uint8_t nchrs[size];
        uint8_t buff[4] = {0};
        uint8_t curr[4] = {0};

        for (uint8_t k = 0; k < size; ++k)
            nchrs[k] = digits[k] - 48;

        while (true)
        {
            buff[i] = letters[nchrs[i] - 2][curr[i]];

            if (size == 1 || ++i == size - 1)
            {
                while (curr[i] < strlen(letters[nchrs[i] - 2]))
                {
                    buff[i] = letters[nchrs[i] - 2][curr[i]++];
                    results.push_back(std::string(reinterpret_cast<char *>(buff), 4));
                }

                while (i >= 0 && curr[i] >= strlen(letters[nchrs[i] - 2]) - 1)
                {
                    if (i == 0)
                        return results;
                    curr[i--] = 0;
                }

                curr[i]++;
            }
        }
    }
};

int main()
{
    Solution solution;

    solution.letterCombinations("29");
    solution.letterCombinations("2345");

    return 0;
}