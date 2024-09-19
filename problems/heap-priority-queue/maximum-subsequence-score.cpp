/**
 * Problem:
 *  LeetCode 75 -> Heap / Priority Queue
 *  2542. Maximum Subsequence Score (Medium)
 *  https://leetcode.com/problems/maximum-subsequence-score/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/maximum-subsequence-score/submissions/1383274688?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      155ms
 *      Beats: 73.34%
 *  Memory
 *      95.79MB
 *      Beats: 64.76%
 *
 * Notes
 *  - This problem was solved with the help of this video:
 *      https://www.youtube.com/watch?v=vJ7ZWmfO1Rw
 */

#include <iostream>
#include <cassert>

#include <vector>
#include <algorithm>
#include <queue>

class Solution
{
private:
    using Pair = std::pair<int, int>;

public:
    long long maxScore(const std::vector<int> &nums1, const std::vector<int> &nums2, int k)
    {
        std::size_t size = nums1.size();
        std::vector<Pair> pairs;

        for (std::size_t i = 0; i < size; ++i)
        {
            pairs.push_back({nums1[i], nums2[i]});
        }

        auto comp = [](const Pair &a, const Pair &b)
        { return a.second > b.second; };
        std::sort(pairs.begin(), pairs.end(), comp);

        std::priority_queue<int, std::vector<int>, std::greater<>> pqueue{std::greater()};

        long long total = 0,
                  max = 0;
        for (const auto &[first, second] : pairs)
        {
            total += first;
            pqueue.push(first);

            if (static_cast<int>(pqueue.size()) > k)
            {
                total -= pqueue.top();
                pqueue.pop();
            }

            if (static_cast<int>(pqueue.size()) == k)
            {
                max = std::max(max, total * second);
            }
        }

        return max;
    }
};

int main()
{
    Solution solution;

    solution.maxScore(std::vector({1, 3, 3, 2}), std::vector({2, 1, 3, 4}), 3);

    return 0;
}