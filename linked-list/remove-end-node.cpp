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

int getLen(ListNode *head)
{
    int len = 0;
    while (head != nullptr)
    {
        len++;
        head = head->next;
    }
    return len;
}

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int len = getLen(head);
        int index = len - n;
        if (index == 0)
        {
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }

        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (index)
        {
            prev = cur;
            cur = cur->next;
            index--;
        }
        prev->next = cur->next;
        delete cur;
        return head;
    }
};