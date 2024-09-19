/**
 * Problem:
 *  LeetCode 75 -> Monotonic Stack
 *  901. Online Stock Span (Medium)
 *  https://leetcode.com/problems/online-stock-span/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/online-stock-span/submissions/1367475182?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      173ms
 *      Beats: 41.17%
 *  Memory
 *      90.34MB
 *      Beats: 58.84%
 */

#include <iostream>
#include <cassert>

#include <stack>

class StockSpanner
{
private:
    using Item =
        struct
    {
        int price;
        std::size_t count;
    };

    std::stack<Item> m_stack;

public:
    StockSpanner()
    {
    }

    int next(int price)
    {
        if (m_stack.empty())
        {
            m_stack.push({.price = price, .count = 0});
            return 1;
        }

        std::size_t count = 0;
        while (!m_stack.empty() && m_stack.top().price <= price)
        {
            count += m_stack.top().count + 1;
            m_stack.pop();
        }

        m_stack.push({ .price = price, .count = count });

        return count + 1;
    }
};

int main()
{
    /**
     * StockSpanner* obj = new StockSpanner();
     * int param_1 = obj->next(price);
     */

    return 0;
}