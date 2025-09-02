#include <string>
#include <unordered_map>

using namespace std;

struct ListNode
{
    bool terminal;
    unordered_map<char, ListNode *> children;
};

class PrefixTree
{
public:
    ListNode *root;

    PrefixTree() : root{new ListNode{false, unordered_map<char, ListNode *>{}}}
    {
    }

    void insert(string word)
    {
        ListNode *cur = root;
        for (char c : word)
        {
            if (cur->children.find(c) == cur->children.end())
            {
                cur->children[c] = new ListNode{false, unordered_map<char, ListNode *>{}};
            }
            cur = cur->children[c];
        }
        cur->terminal = true;
    }

    bool search(string word)
    {
        ListNode *cur = root;
        for (char c : word)
        {
            if (cur->children.find(c) == cur->children.end())
            {
                return false;
            }
            cur = cur->children[c];
        }
        return cur->terminal;
    }

    bool startsWith(string prefix)
    {
        ListNode *cur = root;
        for (char c : prefix)
        {
            if (cur->children.find(c) == cur->children.end())
            {
                return false;
            }
            cur = cur->children[c];
        }
        // Cur guaranteed to be non-null
        return true;
    }
};
