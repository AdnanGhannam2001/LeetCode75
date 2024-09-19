/**
 * Problem:
 *  LeetCode 75 -> Trie
 *  1268. Search Suggestions System (Medium)
 *  https://leetcode.com/problems/search-suggestions-system/description/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/search-suggestions-system/submissions/1381926681?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      109ms
 *      Beats: 42.13%
 *  Memory
 *      64.41MB
 *      Beats: 58.66%
 */

#include <iostream>
#include <cassert>

#include <string>
#include <vector>
#include <map>

class Solution
{
private:
    using Node = struct node
    {
        bool end;
        std::map<char, struct node> sub_nodes;
    };
    using Word = std::string;
    using Words = std::vector<Word>;

private:
    Node m_root;

    constexpr uint8_t min(const uint8_t a, const uint8_t b)
    {
        return a > b ? b : a;
    }

    void get_words(const Node &root, Words &words, Word &word)
    {
        if (words.size() >= 3)
            return;

        if (root.end)
            words.push_back(word);

        if (root.sub_nodes.empty())
            return;

        for (auto &[c, node] : root.sub_nodes)
        {
            word.push_back(c);
            get_words(node, words, word);
            word.pop_back();
        }
    }

    void insert(const Word &word)
    {
        uint16_t length = word.length();
        Node *curr = &m_root;
        for (uint16_t i = 0; i < length; ++i)
        {
            if (curr->sub_nodes.count(word[i]) == 0)
                curr->sub_nodes.insert({word[i], {false, std::map<char, Node>()}});

            curr = &curr->sub_nodes[word[i]];

            if (i == length - 1)
                curr->end = true;
        }
    }

    Words search(const Word &prefix)
    {
        uint16_t length = prefix.length();
        Node *curr = &m_root;
        Words words;

        for (uint16_t i = 0; i < length; ++i)
        {
            if (curr->sub_nodes.count(prefix[i]) == 0)
                return words;

            curr = &curr->sub_nodes[prefix[i]];
        }

        Word word = prefix;
        get_words(*curr, words, word);

        return words;
    }

public:
    Solution()
        : m_root({false, std::map<char, Node>()}) {}

    std::vector<Words> suggestedProducts(const Words &products, const Word &searchWord)
    {
        std::vector<Words> results;

        for (const auto &product : products)
            insert(product);

        uint16_t length = searchWord.length();
        for (uint16_t i = 1; i <= length; ++i)
            results.push_back(search(searchWord.substr(0, i)));

        return results;
    }
};

int main()
{
    return 0;
}