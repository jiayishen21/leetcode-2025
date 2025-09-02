#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode
{
    bool terminal;
    unordered_map<char, TrieNode *> children;
};

class WordDictionary
{
    TrieNode *root;

public:
    WordDictionary() : root{new TrieNode{false, unordered_map<char, TrieNode *>{}}}
    {
    }

    void addWord(string word)
    {
        TrieNode *cur = root;
        for (char c : word)
        {
            if (cur->children.find(c) == cur->children.end())
            {
                cur->children[c] = new TrieNode{false, unordered_map<char, TrieNode *>{}};
            }
            cur = cur->children[c];
        }
        cur->terminal = true;
    }

    bool search(string word)
    {
        return searchHelper(word, root, 0);
    }

    bool searchHelper(string word, TrieNode *node, int index)
    {
        if (index >= word.size())
        {
            return node->terminal;
        }

        char c = word[index];
        if (c == '.')
        {
            // Iterate through all children
            for (const auto &[d, child] : node->children)
            {
                if (searchHelper(word, child, index + 1))
                {
                    return true;
                }
            }
            return false;
        }

        if (node->children.find(c) != node->children.end())
        {
            return searchHelper(word, node->children[c], index + 1);
        }
        return false;
    }
};
