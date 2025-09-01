#include <vector>

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

using namespace std;

ListNode *mergeLists(ListNode *a, ListNode *b)
{
    if (a == nullptr)
    {
        return b;
    }
    if (b == nullptr)
    {
        return a;
    }

    ListNode *merged;
    if (a->val < b->val)
    {
        merged = a;
        a = a->next;
    }
    else
    {
        merged = b;
        b = b->next;
    }
    ListNode *mergedTail = merged;

    while (a != nullptr && b != nullptr)
    {
        if (a->val < b->val)
        {
            mergedTail->next = a;
            a = a->next;
        }
        else
        {
            mergedTail->next = b;
            b = b->next;
        }
        mergedTail = mergedTail->next;
    }

    mergedTail->next = a != nullptr ? a : b;
    return merged;
}

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int k = lists.size();
        ListNode *merged = nullptr;
        for (const auto &list : lists)
        {
            merged = mergeLists(merged, list);
        }
        return merged;
    }
};
