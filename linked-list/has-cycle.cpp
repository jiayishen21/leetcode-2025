/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *turtle = head;
        ListNode *rabbit = head;

        // Initial advance
        turtle = turtle->next;
        rabbit = rabbit->next;
        if (rabbit == nullptr)
        {
            return false;
        }
        rabbit = rabbit->next;
        if (rabbit == nullptr)
        {
            return false;
        }

        while (turtle != rabbit)
        {
            turtle = turtle->next;
            rabbit = rabbit->next;
            if (rabbit == nullptr)
            {
                return false;
            }
            rabbit = rabbit->next;
            if (rabbit == nullptr)
            {
                return false;
            }
        }
        return true;
    }
};
