#include <vector>
#include <unordered_map>

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

using namespace std;

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        unordered_map<Node *, int> nodeToIndex;
        Node *cur = head;
        int index = 0;
        while (cur != nullptr)
        {
            nodeToIndex[cur] = index;
            index++;
            cur = cur->next;
        }

        // Make the deep copy for every node
        vector<Node *> newList;
        cur = head;
        while (cur != nullptr)
        {
            Node *newNode = new Node(cur->val);
            if (!newList.empty())
            {
                newList.back()->next = newNode;
            }
            newList.push_back(newNode);
            cur = cur->next;
        }

        // Set random
        cur = head;
        index = 0;
        while (cur != nullptr)
        {
            if (cur->random != nullptr)
            {
                int randomIndex = nodeToIndex[cur->random];
                newList[index]->random = newList[randomIndex];
            }
            cur = cur->next;
            index++;
        }
        return newList[0];
    }
};
