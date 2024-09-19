/**
 * Problem:
 *  LeetCode 75 -> Queue
 *  649. Dota2 Senate (Medium)
 *  https://leetcode.com/problems/dota2-senate/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/dota2-senate/submissions/1386639362?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      35ms
 *      Beats: 8.73%
 *  Memory
 *      8.32MB
 *      Beats: 94.89%
 */

#include <iostream>
#include <cassert>

#include <string>
#include <queue>

class Solution
{
public:
    std::string predictPartyVictory(std::string &senate)
    {
        uint16_t length = senate.length(),
                 counter = 0,
                 index = 0;

        uint16_t count[2] = {0};
        for (const auto &c : senate)
            count[c == 'D' ? 0 : 1]++;

        uint16_t values[2] = {0};
        while (count[0] > 0 && count[1] > 0)
        {
            if (values[(index = senate[0] == 'D' ? 0 : 1)] == 0)
            {
                values[(index + 1) % 2]++;
                senate.push_back(senate[0]);
            }
            else
            {
                values[index]--;
                count[index]--;
            }
            senate.erase(senate.begin());
        }

        return count[0] > 0 ? "Dire" : "Radiant";
    }
};

int main()
{
    return 0;
}