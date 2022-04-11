#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class SolutionRecursive
{
public:
    pair<ListNode *, ListNode *> reverseList(ListNode *cur, ListNode *prev)
    {
        if (cur == NULL)
            return {NULL, NULL};
        if (cur->next == NULL)
        {
            cur->next = prev;
            return {cur, cur};
        }

        pair<ListNode *, ListNode *> data = reverseList(cur->next, cur);
        ListNode *newHead = data.first, *last = data.second;
        cur->next = prev;
        last = cur;
        return {newHead, last};
    }
    ListNode *reverseList(ListNode *head)
    {
        pair<ListNode *, ListNode *> newHead = reverseList(head, NULL);
        return newHead.first;
    }
};

class SolutionIterative
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *prev = NULL, *cur = head, *next = head->next;

        while (next != NULL)
        {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next->next;
        }
        cur->next = prev;
        return cur;
    }
};