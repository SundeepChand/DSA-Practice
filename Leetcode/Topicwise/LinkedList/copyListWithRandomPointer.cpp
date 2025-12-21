#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class SolutionBruteForce
{
public:
    Node *copyRandomList(Node *head)
    {
        map<Node *, Node *> m;

        Node *cur = head, *newHead = NULL, *newCur = NULL;
        while (cur != NULL)
        {
            if (newHead == NULL)
                newHead = newCur = new Node(cur->val);
            else
                newCur->next = new Node(cur->val), newCur = newCur->next;

            m[cur] = newCur;
            cur = cur->next;
        }
        cur = head, newCur = newHead;
        while (cur != NULL)
        {
            newCur->random = m[cur->random];
            newCur = newCur->next;
            cur = cur->next;
        }
        return newHead;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *cur = head;
        while (cur != NULL)
        {
            Node *newNode = new Node(cur->val);
            newNode->next = cur->next;
            cur->next = newNode;
            cur = newNode->next;
        }
        cur = head;
        while (cur != NULL)
        {
            if (cur->random != NULL)
                cur->next->random = cur->random->next;
            else
                cur->next->random = NULL;
            cur = cur->next->next;
        }

        Node *newList = NULL, *newCur = NULL;
        cur = head;
        while (cur != NULL)
        {
            Node *next = cur->next->next;
            if (newList == NULL)
                newList = newCur = cur->next;
            else
                newCur->next = cur->next, newCur = cur->next;
            cur->next = next;
            cur = next;
        }
        return newList;
    }
};