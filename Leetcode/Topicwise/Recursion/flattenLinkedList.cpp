#include <bits/stdc++.h>
using namespace std;

/* Node structure  used in the program */

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

/*  Function which returns the  root of
    the flattened linked list. */
pair<Node *, Node *> merge(Node *root1, Node *root2)
{
    Node *head = new Node(0);
    Node *cur = head, *cur1 = root1, *cur2 = root2;

    while (cur1 != NULL or cur2 != NULL)
    {
        Node *next;
        if (cur1 == NULL)
        {
            next = cur2;
            cur2 = cur2->next;
        }
        else if (cur2 == NULL)
        {
            next = cur1;
            cur1 = cur1->next;
        }
        else if (cur1->data < cur2->data)
        {
            next = cur1;
            cur1 = cur1->next;
        }
        else
        {
            next = cur2;
            cur2 = cur2->next;
        }
        cout << next->data << endl;
        if (next->bottom != NULL)
        {
            auto sub = merge(next->bottom, next->next);
            next->bottom = sub.first;
            cur->bottom = next;
            cur = sub.second;
            break;
        }
        else
        {
            cur->bottom = next;
            cur = next;
        }
    }
    return {head->bottom, cur};
}

Node *flatten(Node *root)
{
    Node *res = root;
    res->bottom = merge(root->bottom, root->next).first;
    return res;
}