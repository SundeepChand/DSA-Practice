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
    class CompareListNode
    {
    public:
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, CompareListNode> pq;
        for (ListNode *head : lists)
        {
            if (head != NULL)
            {
                pq.push(head);
                head = head->next;
            }
        }

        ListNode *newList = NULL, *cur = newList;
        while (!pq.empty())
        {
            ListNode *front = pq.top();
            pq.pop();

            if (newList == NULL)
                newList = front, cur = newList;
            else
                cur->next = front, cur = cur->next;

            if (front->next != NULL)
                pq.push(front->next);
            front->next = NULL;
        }
        return newList;
    }
};