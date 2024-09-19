/**
 * Problem:
 *  LeetCode 75 -> Graphs - DFS
 *  841. Keys and Rooms (Medium)
 *  https://leetcode.com/problems/keys-and-rooms/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/keys-and-rooms/submissions/1378694630?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      11ms
 *      Beats: 25.91%
 *  Memory
 *      14.29MB
 *      Beats: 36.60%
 */

#include <iostream>
#include <cassert>

#include <vector>

class Solution
{
private:
    void visit_room(const std::vector<std::vector<int>> &rooms, std::size_t index, std::vector<bool> &visited, std::size_t &left)
    {
        if (visited[index])
            return;

        left--;
        visited[index] = true;

        for (const auto &key : rooms[index])
            visit_room(rooms, key, visited, left);
    }

public:
    bool canVisitAllRooms(const std::vector<std::vector<int>> &rooms)
    {
        std::size_t size = rooms.size();
        std::vector<bool> visited(size, false);

        visit_room(rooms, 0, visited, size);

        return size == 0;
    }
};

int main()
{
    Solution solution;

    solution.canVisitAllRooms(std::vector({std::vector({1}), std::vector({2}), std::vector({3}), std::vector<int>({})}));
    solution.canVisitAllRooms(std::vector({
        std::vector({1,3}),
        std::vector({3,0,1}),
        std::vector({2}),
        std::vector({0})
    }));
    return 0;
}