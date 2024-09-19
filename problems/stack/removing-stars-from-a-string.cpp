/**
 * Problem:
 *  LeetCode 75 -> Stack
 *  2390. Removing Stars From a String (Medium)
 *  https://leetcode.com/problems/removing-stars-from-a-string/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/removing-stars-from-a-string/submissions/1387549918?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      665ms
 *      Beats: 5.05%
 *  Memory
 *      22.50MB
 *      Beats: 99.64%
 */

#include <iostream>
#include <cassert>

#include <string>

class Solution
{
public:
    std::string removeStars(const std::string& s)
    {
        std::size_t length = s.length(),
                    count = 0;

        std::string result;

        for (auto iter = s.rbegin(); iter != s.rend(); ++iter)
            if (*iter == '*')
                ++count;
            else if (count > 0)
                --count;
            else
                result.insert(0, 1, *iter);

        return result;
    }
};

int main()
{
    Solution solution;

    assert(solution.removeStars("leet**cod*e") == "lecoe");
    assert(solution.removeStars("erase*****") == "");
    assert(solution.removeStars("abcd***") == "a");
    assert(solution.removeStars("a*b*c*d*e*f*ghijk*lmnop*qrstuv*wxyz*") == "ghijlmnoqrstuwxy");
    return 0;
}