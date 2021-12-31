#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
    // O(1) space using iterations
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return NULL;
        Node *prev = root;
        prev->next == NULL;
        while (prev->left != NULL)
        {
            Node *cur = prev->left, *prev_cur = prev;
            while (prev_cur != NULL)
            {
                if (cur == prev_cur->left)
                    cur->next = prev_cur->right;
                else if (cur == prev_cur->right)
                {
                    if (prev_cur->next == NULL)
                        cur->next = NULL;
                    else
                        cur->next = prev_cur->next->left;
                    prev_cur = prev_cur->next;
                }
                cur = cur->next;
            }
            prev = prev->left;
        }
        return root;
    }
};

class Solution1
{
    // O(N) Space, using BFS
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return NULL;

        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                Node *first = q.front();
                q.pop();
                if (i == s - 1)
                    first->next = NULL;
                else
                    first->next = q.front();
                if (first->left != NULL)
                    q.push(first->left);
                if (first->right != NULL)
                    q.push(first->right);
            }
        }
        return root;
    }
};