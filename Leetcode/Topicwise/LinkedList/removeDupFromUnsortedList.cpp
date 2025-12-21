#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates(Node *head)
    {
        if (head == NULL or head->next == NULL)
            return head;

        unordered_set<int> s;
        s.insert(head->data);
        Node *cur = head, *next = head->next;
        while (next != NULL)
        {
            int val = next->data;
            if (s.find(next->data) != s.end())
            {
                // Delete next
                cur->next = next->next;
                Node *temp = next;
                next = next->next;
                delete temp;
            }
            else
            {
                cur = cur->next;
                next = next->next;
            }
            s.insert(val);
        }
        return head;
    }
};