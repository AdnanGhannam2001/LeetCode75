/**
 * Problem:
 *  LeetCode 75 -> Array / String
 *  605. Can Place Flowers (Easy)
 *  https://leetcode.com/problems/can-place-flowers/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/can-place-flowers/submissions/1387525558?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      3ms
 *      Beats: 99.51%
 *  Memory
 *      23.10MB
 *      Beats: 7.59%
 */

#include <cassert>

#include <vector>
#include <cstdint>

class Solution
{
    inline bool can_place_at(const std::vector<int> &f, uint16_t index, uint16_t size)
    {
        if (f[index] == 0)
        {
            if ((index == 0 && index == size - 1)
                || (index == 0 && index + 1 < size && f[index + 1] != 1)
                || (index == size - 1 && f[index - 1] != 1)
                || (index != 0 && index != size - 1 && f[index + 1] != 1 && f[index - 1] != 1))
                return true;
        }

        return false;
    }

public:
    bool canPlaceFlowers(std::vector<int> &flowerbed, int n)
    {
        uint16_t i = UINT16_MAX,
                 size = flowerbed.size();

        while (n > 0 && ++i < size)
        {
            if (can_place_at(flowerbed, i, size))
            {
                flowerbed[i] = 1;
                n--;
            }
        }

        return n == 0;
    }
};

int main()
{
    Solution solution;

    std::vector<int> vec = {1, 0, 0, 0, 1};
    assert(solution.canPlaceFlowers(vec, 1) == true);
    assert(solution.canPlaceFlowers(vec, 2) == false);

    return 0;
}