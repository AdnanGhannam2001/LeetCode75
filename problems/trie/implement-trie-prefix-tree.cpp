/**
 * Problem:
 *  LeetCode 75 -> Trie
 *  208. Implement Trie (Prefix Tree) (Medium)
 *  https://leetcode.com/problems/implement-trie-prefix-tree/?envType=study-plan-v2&envId=leetcode-75
 *
 * Solution:
 *  https://leetcode.com/problems/implement-trie-prefix-tree/submissions/1381679623?envType=study-plan-v2&envId=leetcode-75
 *  Runtime
 *      85ms
 *      Beats: 11.35%
 *  Memory
 *      46.86MB
 *      Beats: 83.80%
 */

#include <iostream>
#include <cassert>

#include <string>
#include <unordered_map>

class Trie
{
private:
    using Node = struct node
    {
        bool end;
        std::unordered_map<char, struct node> sub_nodes;
    };

    Node m_root;

public:
    Trie()
        : m_root({false, std::unordered_map<char, Node>()})
    {
    }

    void insert(const std::string &word)
    {
        uint16_t length = word.length();
        Node *curr = &m_root;
        for (uint16_t i = 0; i < length; ++i)
        {
            if (curr->sub_nodes.count(word[i]) == 0)
                curr->sub_nodes.insert({word[i], {false, std::unordered_map<char, Node>()}});

            curr = &curr->sub_nodes[word[i]];

            if (i == length - 1)
                curr->end = true;
        }
    }

    bool search(const std::string &word)
    {
        uint16_t length = word.length();
        Node *curr = &m_root;
        for (uint16_t i = 0; i < length; ++i)
        {
            if (curr->sub_nodes.count(word[i]) == 0)
                return false;

            curr = &curr->sub_nodes[word[i]];

            if (i == length - 1 && curr->end)
                return true;
        }

        return false;
    }

    bool startsWith(const std::string &prefix)
    {
        uint16_t length = prefix.length();
        Node *curr = &m_root;
        for (uint16_t i = 0; i < length; ++i)
        {
            if (curr->sub_nodes.count(prefix[i]) == 0)
                return false;

            curr = &curr->sub_nodes[prefix[i]];
        }

        return true;
    }
};

int main()
{
    Trie trie;

    trie.insert("123");
    trie.insert("hello");
    trie.insert("helium");
    trie.search("hello");

    return 0;
}