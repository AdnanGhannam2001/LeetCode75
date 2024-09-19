/**
 * Problem:
 *  LeetCode 75 -> DP - Multidimensional
 *  62. Unique Paths (Medium)
 *  https://leetcode.com/problems/unique-paths/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/unique-paths/submissions/1387277571?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      7ms
 *      Beats: 12.55%
 *  Memory
 *      10.94MB
 *      Beats: 22.16%
 */

#include <iostream>
#include <cassert>

#include <map>

class Solution
{
private:
    using Key = std::pair<int, int>;
    using Value = int;
    using Map = std::map<Key, Value>;

    int uniquePathsImpl(int m, int n, int y, int x, Map &map)
    {
        if (y == m && x == n)
            return 1;
        if (y > m || x > n)
            return 0;

        if (map.count({x, y}) > 0)
            return map[{x, y}];

        return (map[{x, y}] = uniquePathsImpl(m, n, y + 1, x, map) + uniquePathsImpl(m, n, y, x + 1, map));
    }

public:
    int uniquePaths(int m, int n)
    {
        Map map{{std::make_pair(n, m), 10}};
        return uniquePathsImpl(m, n, 1, 1, map);
    }
};

int main()
{
    Solution solution;

    std::cout << solution.uniquePaths(3, 2) << "\n";
    std::cout << solution.uniquePaths(3, 7) << "\n";

    return 0;
}