#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left, *right;

    Node(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};

int Floor(Node *root, int val)
{
    int ans = INT_MIN;
    Node *cur = root;

    while (cur != NULL)
    {
        if (cur->val <= val)
        {
            ans = cur->val;
            cur = cur->right;
        }
        else
            cur = cur->left;
    }
    return ans;
}

int Ceil(Node *root, int val)
{
    int ans = INT_MAX;
    Node *cur = root;

    while (cur != NULL)
    {
        if (cur->val >= val)
        {
            ans = cur->val;
            cur = cur->left;
        }
        else
            cur = cur->right;
    }
    return ans;
}

int main()
{
    Node *root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    int val = 13;
    cout << Floor(root, val) << ", " << Ceil(root, val) << endl;

    return 0;
}