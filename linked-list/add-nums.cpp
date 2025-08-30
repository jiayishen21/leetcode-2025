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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *newNum = new ListNode(l1->val + l2->val);
        l1 = l1->next;
        l2 = l2->next;

        ListNode *cur = newNum;
        while (l1 != nullptr || l2 != nullptr)
        {
            int carry = cur->val / 10;
            cur->val %= 10;
            cur->next = new ListNode(carry);
            cur = cur->next;

            if (l1 != nullptr)
            {
                cur->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                cur->val += l2->val;
                l2 = l2->next;
            }
        }
        int carry = cur->val / 10;
        cur->val %= 10;
        if (carry)
        {
            cur->next = new ListNode(carry);
        }

        return newNum;
    }
};
