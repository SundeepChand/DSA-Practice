#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node *left, *right;

        Node(int data)
        {
            this->val = data;
            left = right = NULL;
        }
};

pair<Node*, Node*> flatten(Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return {root, root};
    }
    if (root->left == NULL)
    {
        pair<Node*, Node*> right = flatten(root->right);
        root->right = right.first;
        return {root, right.second};
    }
    if (root->right == NULL)
    {
        pair<Node*, Node*> left = flatten(root->left);
        left.second->right = root;
        root->left = NULL;
        return {left.first, root};
    }
    
    pair<Node*, Node*> left = flatten(root->left);
    pair<Node*, Node*> right = flatten(root->right);
    
    root->left = NULL;
    left.second->right = root;
    root->right = right.first;

    return { left.first, right.second };
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    root = flatten(root).first;

    Node *cur = root;
    while (cur != NULL)
    {
        cout<<cur->val<<" -> ";
        cur = cur->right;
    }
    cout<<endl;
    return 0;
}