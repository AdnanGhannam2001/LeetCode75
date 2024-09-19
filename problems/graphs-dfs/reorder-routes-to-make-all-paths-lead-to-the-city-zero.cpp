/**
 * Problem:
 *  LeetCode 75 -> Graphs - DFS
 *  1466. Reorder Routes to Make All Paths Lead to the City Zero (Medium)
 *  https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/submissions/1379525407?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      664ms
 *      Beats: 11.01%
 *  Memory
 *      126.28MB
 *      Beats: 41.46%
 */

#include <iostream>
#include <cassert>

#include <vector>
#include <unordered_map>

class Solution
{
private:
    using Nighbour = std::pair<int, bool>;
    using TraverseMap = std::unordered_map<int, std::pair<bool, std::vector<Nighbour>>>;

    void init_or_push(TraverseMap &traverseMap, int value, const Nighbour &nighbour)
    {
        if (traverseMap.count(value) == 0)
            traverseMap[value] = {false, std::vector({nighbour})};
        else
            traverseMap[value].second.push_back(nighbour);
    }

    int minReorderImpl(TraverseMap &traverseMap, int key)
    {
        auto &current = traverseMap[key];
        current.first = true;

        int sum = 0;
        for (const auto &nighbour : current.second)
        {
            if (traverseMap[nighbour.first].first)
                continue;

            if (!nighbour.second)
                sum++;

            sum += minReorderImpl(traverseMap, nighbour.first);
        }

        return sum;
    }

public:
    int minReorder(int n, const std::vector<std::vector<int>> &connections)
    {
        TraverseMap traverseMap;
        for (const auto &connection : connections)
        {
            init_or_push(traverseMap, connection[0], std::pair(connection[1], false));
            init_or_push(traverseMap, connection[1], std::pair(connection[0], true));
        }

        return minReorderImpl(traverseMap, 0);
    }
};

int main()
{
    Solution solution;

    std::cout << solution.minReorder(6, std::vector({std::vector({0, 1}), std::vector({1, 3}), std::vector({2, 3}), std::vector({4, 0}), std::vector({4, 5})}))
              << "\n";

    return 0;
}
