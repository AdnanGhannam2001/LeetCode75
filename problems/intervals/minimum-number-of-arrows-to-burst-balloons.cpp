/**
 * Problem:
 *  LeetCode 75 -> Intervals
 *  452. Minimum Number of Arrows to Burst Balloons (Medium)
 *  https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/submissions/1385425671?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      264ms
 *      Beats: 37.39%
 *  Memory
 *      93.59MB
 *      Beats: 73.43%
 */

#include <iostream>
#include <cassert>

#include <vector>
#include <algorithm>

static void print_interval(const std::vector<std::vector<int>> &intervals)
{
    std::cout << "[\n";
    for (const auto &interval : intervals)
    {
        std::cout << "\t[ ";
        for (const auto &val : interval)
        {
            std::cout << val << " ";
        }
        std::cout << "]\n";
    }
    std::cout << "]\n";
}

class Solution
{
private:
    using SInterval = struct
    {
        int x, y;
    };
    using Interval = std::vector<int>;
    using Intervals = std::vector<Interval>;
    using IntervalsCIter = Intervals::const_iterator;

    static bool intervals_intersect(int x1, int y1, int x2, int y2)
    {
        return (x1 == x2 && y1 == y2) || (x2 <= y1 && x1 <= y2);
    }

public:
    int findMinArrowShots(Intervals &points)
    {
        int acc = 1;
        std::sort(points.begin(), points.end(), [](const Interval &a, const Interval &b)
                  { return a[1] < b[1]; });

        SInterval curr = {points.back()[0], points.back()[1]};
        for (int i = points.size() - 2; i >= 0; --i)
            if (!intervals_intersect(curr.x, curr.y, points[i][0], points[i][1]))
                curr = {points[i][0], points[i][1]}, acc++;
            else
                curr = {std::max(curr.x, points[i][0]), std::min(curr.y, points[i][1])};

        return acc;
    }
};

int main()
{
    Solution solution;

    std::vector<std::vector<int>> intervals =
        {
            {1, 2},
            {2, 3},
            {3, 4},
            {1, 3},
        };
    std::cout << solution.findMinArrowShots(intervals) << "\n";
    intervals =
        {
            {1, 2},
            {1, 2},
            {1, 2},
        };
    std::cout << solution.findMinArrowShots(intervals) << "\n";
    intervals =
        {
            {1, 100},
            {11, 22},
            {1, 11},
            {2, 12}};
    std::cout << solution.findMinArrowShots(intervals) << "\n";
    intervals =
        {
            {1, 2},
            {3, 4},
            {5, 6},
            {7, 8}};
    std::cout << solution.findMinArrowShots(intervals) << "\n";

    return 0;
}