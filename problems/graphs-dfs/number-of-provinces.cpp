/**
 * Problem:
 *  LeetCode 75 -> Graphs - DFS
 *  547. Number of Provinces (Medium)
 *  https://leetcode.com/problems/number-of-provinces/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/number-of-provinces/submissions/1378709525?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      25ms
 *      Beats: 29.08%
 *  Memory
 *      18.40MB
 *      Beats: 81.14%
 */

#include <iostream>
#include <cassert>

#include <vector>

class Solution
{
private:
    void visit_city(const std::vector<std::vector<int>> &cities, std::size_t index, std::vector<bool> &visited)
    {
        if (visited[index])
            return;

        visited[index] = true;

        std::size_t size = cities[index].size();
        for (std::size_t i = 0; i < size; ++i)
             if (cities[index][i] != 0) visit_city(cities, i, visited);
    }
public:
    int findCircleNum(const std::vector<std::vector<int>> &cities)
    {
        std::size_t size = cities.size();
        int count = 0;

        std::vector<bool> visited(size, false);

        for (std::size_t i = 0; i < size; ++i)
        {
            if (visited[i])
                continue;
            
            count++;
            visit_city(cities, i, visited);
        }

        std::cout << count << "\n";
        return count;
    }
};

int main()
{
    Solution solution;

    solution.findCircleNum(std::vector({
        std::vector({1,1,0}),
        std::vector({1,1,0}),
        std::vector({0,0,1})
    }));

    solution.findCircleNum(std::vector({
        std::vector({1,0,0}),
        std::vector({0,1,0}),
        std::vector({0,0,1}),
    }));
    return 0;
}