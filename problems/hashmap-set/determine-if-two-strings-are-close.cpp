/**
 * Problem:
 *  LeetCode 75 -> Hash Map / Set
 *  1657. Determine if Two Strings Are Close (Medium)
 *  https://leetcode.com/problems/determine-if-two-strings-are-close/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/determine-if-two-strings-are-close/submissions/1387547147?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      112ms
 *      Beats: 29.30%
 *  Memory
 *      23.74MB
 *      Beats: 21.20%
 */

#include <iostream>
#include <cassert>

#include <string>
#include <unordered_map>
#include <map>

class Solution
{
private:
    template <typename T>
    static void insert_or_increase(T &map, const char c)
    {
        auto item = map.find(c);
        if (item != map.end())
            item->second++;
        else
            map[c] = 1;
    }
public:
    bool closeStrings(std::string word1, std::string word2)
    {
        std::size_t size = word1.size();

        std::map<char, std::size_t>
            freq_map1,
            freq_map2;

        if (size != word2.size())
            return false;

        for (std::size_t i = 0; i < size; ++i)
        {
            insert_or_increase(freq_map1, word1[i]);
            insert_or_increase(freq_map2, word2[i]);
        }

        std::size_t map_size = freq_map1.size();

        if (map_size != freq_map2.size())
            return false;

        std::unordered_map<std::size_t, std::size_t> f1;
        std::unordered_map<std::size_t, std::size_t> f2;
        for (auto a = freq_map1.begin(), b = freq_map2.begin(); a != freq_map1.end() && b != freq_map2.end(); ++a, ++b)
        {
            if (a->first != b->first)
                return false;
            insert_or_increase(f1, a->second);
            insert_or_increase(f2, b->second);
        }

        for (const auto& [f, n] : f1)
            if (n != f2[f])
                return false;

        return true;
    }
};

int main()
{
    Solution solution;

    assert(solution.closeStrings("abc", "bca") == true);
    assert(solution.closeStrings("aa", "ab") == false);
    assert(solution.closeStrings("cabbba", "abbccc") == true);
    assert(solution.closeStrings("uau", "ssx") == false);
    assert(solution.closeStrings("aaabbbbccddeeeeefffff", "aaaaabbcccdddeeeeffff") == false);

    return 0;
}