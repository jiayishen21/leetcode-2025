#include <iostream>

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

ListNode *reverseList(ListNode *head)
{
    ListNode *cur = head;
    ListNode *prev = nullptr;
    while (cur)
    {
        ListNode *tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }
    return prev;
}

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        int len = getLen(head);
        if (len <= 2)
        {
            return;
        }

        int halfLen = len / 2;
        ListNode *firstHalf = head;
        ListNode *secondHalf = nullptr;
        ListNode *midNode = nullptr;
        ListNode *cur = head;
        for (int i = 0; i < halfLen; i++)
        {
            cur = cur->next;
        }

        if (len % 2)
        {
            secondHalf = cur->next;
            midNode = cur;
            midNode->next = nullptr;
        }
        else
        {
            secondHalf = cur;
        }
        secondHalf = reverseList(secondHalf);

        cur = firstHalf;
        firstHalf = firstHalf->next;

        cur->next = secondHalf;
        cur = cur->next;
        secondHalf = secondHalf->next;

        while (secondHalf != nullptr)
        {
            cur->next = firstHalf;
            cur = cur->next;
            firstHalf = firstHalf->next;

            cur->next = secondHalf;
            cur = cur->next;
            secondHalf = secondHalf->next;
        }
        cur->next = midNode;
    }
};
