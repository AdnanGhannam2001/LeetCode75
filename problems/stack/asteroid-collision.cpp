/**
 * Problem:
 *  LeetCode 75 -> Stack
 *  735. Asteroid Collision (Medium)
 *  https://leetcode.com/problems/asteroid-collision/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/asteroid-collision/submissions/1365311454?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      8ms
 *      Beats: 74.21%
 *  Memory
 *      20.27MB
 *      Beats: 91.35%
 */

#include <iostream>
#include <cassert>

#include <vector>

class Solution
{
public:
    std::vector<int> asteroidCollision(const std::vector<int>& asteroids)
    {
        std::size_t size = asteroids.size(),
                    i = 0;

        std::vector<int> results;

        while (i < size && asteroids[i] < 0)
        {
            results.push_back(asteroids[i++]);
        }

        while (i < size)
        {
            if (asteroids[i] > 0)
            {
                results.push_back(asteroids[i]);
            }
            else
            {
                if (results.empty())
                {
                    results.push_back(asteroids[i]);
                }
                else
                {
                    while (!results.empty())
                    {
                        if (results.back() > 0 && results.back() < -asteroids[i])
                        {
                            results.pop_back();
                            if (results.empty())
                            {
                                results.push_back(asteroids[i]);
                                break;
                            }
                        }
                        else
                        {
                            if (results.back() < 0) results.push_back(asteroids[i]);
                            else if (results.back() == -asteroids[i]) results.pop_back();
                            break;
                        }
                    }
                }
            }

            i++;
        }

        return results;
    }
};

int main()
{
    Solution solution;

    solution.asteroidCollision(std::vector({46, -36, 3, 39, 20, -33, 35, 4, -26, -37, 27, -50, -23, 48, 5, -1, 29, -34, 34, 11, 22, 8, 41, -20, -10, 17, 35, -14, -9, 3, 12, -13, -47, 23, -39, 25, -43, -2, 26, -26, -42, -5, -4, 34, 3, 25, 20, 27, -6}));

    return 0;
}