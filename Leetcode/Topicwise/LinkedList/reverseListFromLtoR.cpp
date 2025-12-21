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

class SolutionStuti
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *c = head, *p = nullptr, *s = nullptr, *e = nullptr, *sp = nullptr, *en = nullptr, *nt;
        int i = 0;
        while (c != nullptr)
        {
            i++;
            if (i == left)
            {
                s = c, sp = p;
                while (i <= right)
                {
                    nt = c->next;
                    c->next = p;
                    p = c;
                    c = nt;
                    i++;
                }
                e = p;
                en = c;
                if (sp != nullptr)
                {
                    sp->next = e;
                }
                cout << s;
                s->next = en;
                cout << s;
            }
            else
            {
                p = c;
                c = c->next;
            }
        }

        if (s == head)
        {
            head = e;
        }
        return head;
    }
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {

        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        ListNode *leftNode = newHead, *rightNode = newHead;

        for (int i = 0; i < left - 1; i++)
            leftNode = leftNode->next, rightNode = rightNode->next;

        ListNode *reverseListEnd = leftNode->next;
        ListNode *prev = NULL, *cur = leftNode->next, *next = cur->next;
        rightNode = cur;
        for (int i = 0; i < right - left; i++)
        {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next->next;
        }
        rightNode = cur->next;
        cur->next = prev;
        leftNode->next = cur;
        reverseListEnd->next = rightNode;
        return newHead->next;
    }
};