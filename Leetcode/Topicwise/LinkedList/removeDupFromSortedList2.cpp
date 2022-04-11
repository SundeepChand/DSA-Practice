#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1
{
    // Solution using sentinel node.
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *newHead = new ListNode(-1);
        newHead->next = head;

        ListNode *prev = newHead, *cur = head, *next = head->next;
        bool toErase = false;
        while (next != NULL)
        {
            if (next->val == cur->val)
            {
                while (next != NULL && next->val == cur->val)
                    next = next->next, cur = cur->next;
                prev->next = cur->next;
                cur = cur->next;
                if (next != NULL)
                    next = next->next;
            }
            else
                prev = cur, cur = next, next = next->next;
        }
        return newHead->next;
    }
};

class Solution2
{
    // Solution using stack
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        stack<ListNode *> s;

        ListNode *cur = head;
        bool toPop = false;
        while (cur != NULL)
        {
            if (s.empty())
                s.push(cur);
            else
            {
                if (s.top()->val == cur->val)
                    toPop = true;
                else
                {
                    if (toPop)
                        s.pop();
                    s.push(cur);
                    toPop = false;
                }
            }
            cur = cur->next;
        }
        if (toPop)
            s.pop();
        ListNode *newHead = NULL;
        while (!s.empty())
        {
            s.top()->next = newHead;
            newHead = s.top();
            s.pop();
        }
        return newHead;
    }
};