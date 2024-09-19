/**
 * Problem:
 *  LeetCode 75 -> Intervals
 *  435. Non-overlapping Intervals (Medium)
 *  https://leetcode.com/problems/non-overlapping-intervals/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/non-overlapping-intervals/submissions/1385334767?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      229ms
 *      Beats: 80.03%
 *  Memory
 *      93.70MB
 *      Beats: 32.70%
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
    using Interval = std::vector<int>;
    using Intervals = std::vector<Interval>;
    using IntervalsCIter = Intervals::const_iterator;

    static void move_first(IntervalsCIter& first, IntervalsCIter& second)
    {
        first = second++;
    }

    static void move_second(IntervalsCIter& second)
    {
        second++;
    }

    static bool intervals_intersect(IntervalsCIter& first, IntervalsCIter& second)
    {
        return ((*first)[0] == (*second)[0] && (*first)[1] == (*second)[1])
            || (((*first)[1] > (*second)[0]) && (*second)[1] > (*first)[0]);
    }

public:
    int eraseOverlapIntervals(Intervals &intervals)
    {
        int acc = 0;

        std::sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b)
                  { return a[0] < b[0]; });

        IntervalsCIter first = intervals.begin(),
                       second = intervals.begin() + 1;

        print_interval(intervals);

        while (second != intervals.end())
        {
            if (!intervals_intersect(first, second))
            {
                move_first(first, second);
                continue;
            }

            acc++;
            if ((*first)[0] <= (*second)[0] && (*second)[1] <= (*first)[1])
                move_first(first, second);
            else if ((*second)[0] <= (*first)[0] && (*first)[1] <= (*second)[1] )
                move_second(second);
            else if ((*second)[0] < (*first)[0] && (*second)[1] < (*first)[1])
                move_first(first, second);
            else if ((*first)[0] < (*second)[0] && (*first)[1] < (*second)[1])
                move_second(second);
        }

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
    std::cout << solution.eraseOverlapIntervals(intervals) << "\n";
    intervals =
        {
            {1, 2},
            {1, 2},
            {1, 2},
        };
    std::cout << solution.eraseOverlapIntervals(intervals) << "\n";
    intervals =
        {
            {1,100},
            {11,22},
            {1,11},
            {2,12}
        };
    std::cout << solution.eraseOverlapIntervals(intervals) << "\n";

    return 0;
}