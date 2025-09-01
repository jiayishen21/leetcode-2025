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

ListNode *getKthIfExists(ListNode *start, int k)
{
    ListNode *cur = start;
    for (int i = 0; i < k - 1; i++)
    {
        if (cur == nullptr)
        {
            return nullptr;
        }
        cur = cur->next;
    }
    return cur;
}

void reverse(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *cur = head;

    while (cur != nullptr)
    {
        ListNode *next = cur->next;
        cur->next = prev;

        prev = cur;
        cur = next;
    }
}

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *prevTail = nullptr;
        ListNode *cur = head;
        ListNode *curEnd = getKthIfExists(cur, k);

        while (curEnd != nullptr)
        {
            // Set cur section to an isolated list to easily reverse the k group
            ListNode *nextCur = curEnd->next;
            curEnd->next = nullptr;
            reverse(cur);

            if (prevTail != nullptr)
            {
                prevTail->next = curEnd;
            }
            else
            {
                head = curEnd;
            }
            prevTail = cur;

            cur = nextCur;
            curEnd = getKthIfExists(cur, k);
        }
        prevTail->next = cur;

        return head;
    }
};
