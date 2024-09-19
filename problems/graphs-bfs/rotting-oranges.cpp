/**
 * Problem:
 *  LeetCode 75 -> Graphs - BFS
 *  994. Rotting Oranges (Medium)
 *  https://leetcode.com/problems/rotting-oranges/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/rotting-oranges/submissions/1381258742?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      3ms
 *      Beats: 84.31%
 *  Memory
 *      18.26MB
 *      Beats: 5.06%
 */

#include <iostream>
#include <cassert>

#include <vector>
#include <queue>

class Solution
{
private:
    using Position = struct
    {
        int x, y;
    };
    using Queue = std::queue<std::pair<Position, uint8_t>>;

    std::vector<Position> get_directions(const Position &position, std::size_t rows, std::size_t columns)
    {
        std::vector<Position> directions;

        if (position.y > 0)
            directions.push_back({position.x, position.y - 1});

        if (position.x > 0)
            directions.push_back({position.x - 1, position.y});

        if (position.y < rows - 1)
            directions.push_back({position.x, position.y + 1});

        if (position.x < columns - 1)
            directions.push_back({position.x + 1, position.y});

        return directions;
    }

public:
    int orangesRotting(std::vector<std::vector<int>> &grid)
    {
        uint8_t rows = grid.size(),
                columns = grid[0].size();

        Queue queue;
        for (uint8_t y = 0; y < rows; ++y)
            for (uint8_t x = 0; x < columns; ++x)
                if (grid[y][x] == 2)
                    queue.push({{x, y}, 0});

        uint8_t minutes = 0;
        while (!queue.empty())
        {
            auto curr = queue.front();
            queue.pop();
            if (minutes != curr.second) minutes++;
            for (const auto &direction : get_directions(curr.first, rows, columns))
            {
                if (grid[direction.y][direction.x] == 1)
                {
                    grid[direction.y][direction.x] = 2;
                    queue.push({{direction.x, direction.y}, minutes});
                }
            }
        }

        for (const auto &row : grid)
            for (const auto &cell : row)
                if (cell == 1)
                    return -1;

        return minutes;
    }
};

int main()
{
    return 0;
}