/**
 * Problem:
 *  LeetCode 75 -> Graphs - BFS
 *  1926. Nearest Exit from Entrance in Maze (Medium)
 *  https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/submissions/1381206057?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      138ms
 *      Beats: 21.53%
 *  Memory
 *      51.42MB
 *      Beats: 13.63%
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
    using VisitingMap = std::vector<std::vector<bool>>;
    using Map = std::vector<std::vector<char>>;
    using QueueItem = std::pair<Position, int>;
    using Queue = std::queue<QueueItem>;

    inline int min(int a, int b)
    {
        return a < b ? a : b;
    }

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

    void queue_push(Queue &queue, VisitingMap &visiting_map, const QueueItem &item)
    {
        queue.push(item);
        visiting_map[item.first.y][item.first.x] = true;
    }

    bool is_entrance(const std::vector<int> &entrance, int x, int y)
    {
        return x == entrance[1] && y == entrance[0];
    }

public:
    int nearestExit(Map &maze, std::vector<int> &entrance)
    {
        uint8_t rows = maze.size(),
                columns = maze[0].size();
        VisitingMap visiting_map(rows, std::vector(columns, false));
        Queue queue;

        for (uint8_t i = 0; i < rows; ++i)
            if (maze[i][0] == '.' && !is_entrance(entrance, 0, i))
                queue_push(queue, visiting_map, {{0, i}, 0});
        for (uint8_t i = 0; i < rows; ++i)
            if (maze[i][columns - 1] == '.' && !is_entrance(entrance, columns - 1, i))
                queue_push(queue, visiting_map, {{columns - 1, i}, 0});

        for (uint8_t i = 0; i < columns; ++i)
            if (maze[0][i] == '.' && !is_entrance(entrance, i, 0))
                queue_push(queue, visiting_map, {{i, 0}, 0});
        for (uint8_t i = 0; i < columns; ++i)
            if (maze[rows - 1][i] == '.' && !is_entrance(entrance, i, rows - 1))
                queue_push(queue, visiting_map, {{i, rows - 1}, 0});

        if (queue.empty())
            return -1;

        auto curr = queue.front();
        queue.pop();

        while (true)
        {
            std::cout << "Visiting: " << curr.first.x << ", " << curr.first.y << "\n";
            std::vector<Position> directions = get_directions(curr.first, rows, columns);

            for (const auto &direction : directions)
            {
                if (maze[direction.y][direction.x] != '+' && !visiting_map[direction.y][direction.x])
                {
                    if (is_entrance(entrance, direction.x, direction.y))
                        return curr.second + 1;
                    else
                        queue_push(queue, visiting_map, {direction, curr.second + 1});
                }
            }

            if (queue.empty())
                return -1;

            curr = queue.front();
            queue.pop();
        }
    }
};

int main()
{
    Solution solution;

    return 0;
}
