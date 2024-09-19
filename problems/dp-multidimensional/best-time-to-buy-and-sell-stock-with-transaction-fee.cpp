/**
 * Problem:
 *  LeetCode 75 -> DP - Multidimensional
 *  714. Best Time to Buy and Sell Stock with Transaction Fee (Medium)
 *  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/submissions/1387461170?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      66ms
 *      Beats: 92.64%
 *  Memory
 *      57.65MB
 *      Beats: 88.14%
 *
 * Notes:
 *  - The DP solution is taken from this article:
 *      https://dev.to/seanpgallivan/solution-best-time-to-buy-and-sell-stock-with-transaction-fee-5dlp
 */

#include <iostream>
#include <cassert>

#include <vector>

class Solution
{
private:
    // Old solution without DP
    // Init Call: maxProfitImpl(0, -1, prices, fee);
    int maxProfitImpl(std::size_t index, int buy, const std::vector<int> &prices, int fee)
    {
        if (index >= prices.size())
            return 0;

        if (buy == -1)
            return std::max(
                maxProfitImpl(index + 1, index, prices, fee),
                maxProfitImpl(index + 1, -1, prices, fee));

        return std::max(
            prices[index] - prices[buy] - fee + maxProfitImpl(index + 1, -1, prices, fee),
            maxProfitImpl(index + 1, buy, prices, fee));
    }

public:
    int maxProfit(const std::vector<int> &prices, int fee)
    {
        int size = prices.size(),
            buying = 0,
            selling = -prices[0];
        for (int i = 1; i < size; i++)
        {
            buying = std::max(buying, selling + prices[i] - fee);
            selling = std::max(selling, buying - prices[i]);
        }
        return buying;
    }
};

int main()
{
    Solution solution;

    std::cout << solution.maxProfit({1, 3, 2, 8, 4, 9}, 2) << "\n";
    std::cout << solution.maxProfit({1, 3, 7, 5, 10, 3}, 3) << "\n";

    return 0;
}