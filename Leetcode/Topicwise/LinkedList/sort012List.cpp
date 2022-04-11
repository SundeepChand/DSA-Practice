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
    Node *segregate(Node *head)
    {
        Node *newHead = new Node(-1), *one = new Node(-1), *two = new Node(-1);
        Node *zero = newHead;
        zero->next = one, one->next = two;

        Node *cur = head;
        while (cur != NULL)
        {
            Node *temp = cur->next;
            if (cur->data == 0)
            {
                cur->next = zero->next;
                zero->next = cur;
                zero = cur;
            }
            else if (cur->data == 1)
            {
                cur->next = one->next;
                one->next = cur;
                one = cur;
            }
            else if (cur->data == 2)
            {
                cur->next = two->next;
                two->next = cur;
                two = cur;
            }
            cur = temp;
        }
        zero->next = zero->next->next;
        if (zero->next->next != NULL && zero->next->data == -1)
            zero->next = zero->next->next;
        one->next = one->next->next;
        while (newHead->data == -1)
            newHead = newHead->next;
        return newHead;
    }
};