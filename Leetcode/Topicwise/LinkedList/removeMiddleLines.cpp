#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

class ListNode
{
public:
    pair<int, int> val;
    ListNode *next;

    ListNode(pair<int, int> val)
    {
        this->val = val;
        next = NULL;
    }
};

class Solution
{
public:
    void removePoints(ListNode *head)
    {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return;
        ListNode *prev = head, *cur = head->next, *next = head->next->next;
        while (next != NULL)
        {
            if (
                (prev->val.first == cur->val.first && cur->val.first == next->val.first) ||
                (prev->val.second == cur->val.second && cur->val.second == next->val.second))
            {
                prev->next = next;
                delete cur;
            }
            else
                prev = cur;
            cur = next;
            next = next->next;
        }
    }

    void printList(ListNode *head)
    {
        while (head != NULL)
        {
            cout << "(" << head->val.first << ", " << head->val.second << "), ";
            head = head->next;
        }
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    pair<int, int> val;
    cin >> val.first >> val.second;
    ListNode *head = new ListNode(val);
    ListNode *cur = head;
    for (int i = 1; i < n; i++)
    {
        cin >> val.first >> val.second;
        cur->next = new ListNode(val);
        cur = cur->next;
    }

    Solution s;
    s.removePoints(head);
    s.printList(head);

    return 0;
}