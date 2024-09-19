/**
 * Problem:
 *  LeetCode 75 -> Backtracking
 *  216. Combination Sum III (Medium)
 *  https://leetcode.com/problems/combination-sum-iii/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/combination-sum-iii/submissions/1385174147?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      0ms
 *      Beats: 100.00%
 *  Memory
 *      7.72MB
 *      Beats: 96.24%
 */

#include <iostream>
#include <cassert>

#include <vector>

#define END 10

class Solution
{
private:
    void backtrack(uint8_t *nodes, uint8_t &node_ptr, uint8_t &sum)
    {
        sum -= nodes[--node_ptr];
        if (node_ptr != 0)
            sum -= nodes[--node_ptr];
        nodes[node_ptr]++;
    }

public:
    std::vector<std::vector<int>> combinationSum3(int k, int n)
    {
        uint8_t node_ptr = 0,
                sum = 0;

        uint8_t nodes[END];
        nodes[0] = 1;

        std::vector<std::vector<int>> results;
        std::vector<int> result;
        while (true)
        {
            nodes[node_ptr + 1] = nodes[node_ptr] + 1;
            sum += nodes[node_ptr++];

            if (sum == n && node_ptr == k)
            {
                for (uint8_t i = 0; i < node_ptr; ++i)
                    result.push_back(nodes[i]);

                results.push_back(result);
                result.clear();
            }

            if (sum >= n)
            {
                backtrack(nodes, node_ptr, sum);
            }

            if (nodes[node_ptr] >= END)
            {
                if (node_ptr == 0)
                    break;
                backtrack(nodes, node_ptr, sum);
            }
        }

        return results;
    }
};

int main()
{
    Solution solution;

    solution.combinationSum3(3, 7);
    solution.combinationSum3(3, 9);
    solution.combinationSum3(4, 1);
    solution.combinationSum3(2, 18);
    solution.combinationSum3(3, 15);

    return 0;
}