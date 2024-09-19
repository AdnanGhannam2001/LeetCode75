/**
 * Problem:
 *  LeetCode 75 -> Array / String
 *  443. String Compression (Medium)
 *  https://leetcode.com/problems/string-compression/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/string-compression/submissions/1387532855?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      4ms
 *      Beats: 70.97%
 *  Memory
 *      13.03MB
 *      Beats: 87.85%
 */

#include <iostream>
#include <cassert>

#include <vector>
#include <cmath>

class Solution
{
public:
    int compress(std::vector<char>& chars)
    {
        std::size_t i = 0,
                    acc = 0;

        char first = chars[i++];

        while (i <= chars.size())
        {
            if (i == chars.size() || chars[i] != first)
            {
                if (acc++ > 0)
                {
                    char number[5] = {0};
                    sprintf(number, "%lu", acc);
                    for (const auto &n : number)
                    {
                        if (n == '\0') break;
                        chars.insert(chars.begin() + i++, n);
                    }
                }

                if (++i < chars.size())
                    first = chars[i - 1];
                acc = 0;
            }
            else
            {
                chars.erase(chars.begin() + i);
                acc++;
            }
        }

        return chars.size();
    }
};

int main()
{
    Solution solution;

    {
        std::vector vec({'a', 'a', 'b', 'b', 'c', 'c', 'c'});
        assert(solution.compress(vec) == 6);
    }
    {
        std::vector vec({'a'});
        assert(solution.compress(vec) == 1);
    }
    {
        std::vector vec({'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'});
        assert(solution.compress(vec) == 4);
    }
    {
        std::vector vec({'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'});
        assert(solution.compress(vec) == 3);
    }
    {
        std::vector vec({'1', '1', '2'});
        assert(solution.compress(vec) == 3);
    }
    {
        std::vector vec({'a', 'b', 'c', 'd', 'e', 'f'});
        assert(solution.compress(vec) == 6);
    }

    return 0;
}