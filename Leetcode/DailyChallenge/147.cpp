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

class Solution
{
public:
    ListNode *insert(int val, ListNode *head)
    {
        if (head == NULL || val <= head->val)
        {
            head = new ListNode(val, head);
        }
        else
        {
            ListNode *cur = head;
            while (cur->next != NULL && cur->next->val < val)
                cur = cur->next;
            ListNode *newNode = new ListNode(val, cur->next);
            cur->next = newNode;
        }
        return head;
    }

    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *newHead = NULL, *cur = head;
        while (cur != NULL)
        {
            newHead = insert(cur->val, newHead);
            ListNode *temp = cur;
            cur = cur->next;
            delete temp;
        }
        return newHead;
    }
};