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
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        next = NULL;
    }
};

class Solution
{
public:
    void reverseEvenPosNodes(ListNode *head)
    {
        ListNode *evenHead = NULL, *cur = head;
        while (cur != NULL and cur->next != NULL)
        {
            ListNode *next = cur->next->next;
            cur->next->next = evenHead;
            evenHead = cur->next;
            cur->next = next;
            cur = next;
        }

        // Merge the odd and even lists.
        cur = head;
        while (cur != NULL and evenHead != NULL)
        {
            ListNode *evenNext = evenHead->next;
            evenHead->next = cur->next;
            cur->next = evenHead;
            evenHead = evenNext;
            cur = cur->next->next;
        }
    }

    void printList(ListNode *head)
    {
        while (head != NULL)
        {
            cout << head->val << ", ";
            head = head->next;
        }
        cout << endl;
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

    ListNode *head = NULL, *cur = NULL;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ListNode *newNode = new ListNode(x);
        if (head == NULL)
            head = cur = newNode;
        else
            cur->next = newNode, cur = newNode;
    }

    Solution s;
    s.reverseEvenPosNodes(head);
    s.printList(head);

    return 0;
}