#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *left, *right;

        Node(int data)
        {
            this->data = data;
            left = right = NULL;
        }
};

Node* buildTree()
{
    // Build a tree, in a pre-order fashion by taking
    // input from STDIN
    int data;
    cin>>data;

    if (data == -1)
    {
        return NULL;
    }

    Node* cur = new Node(data);
    cur->left = buildTree();
    cur->right = buildTree();
    return cur;
}

void preorderTraversal(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout<<head->data<<", ";
    preorderTraversal(head->left);
    preorderTraversal(head->right);
}

int replaceWithDesc(Node* root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
    {
        // The node is a leaf node
        return root->data;
    }

    int left = replaceWithDesc(root->left);
    int right = replaceWithDesc(root->right);
    int temp = root->data;
    root->data = left + right;
    return temp + root->data;
}

int main()
{
    /*
    Example tree: 4 2 3 -1 5 -1 -1 1 4 -1 -1 -1 7 -1 8 -1 -1
    */
    Node* root = buildTree();

    cout<<"Before replacement:"<<endl;
    preorderTraversal(root);
    cout<<endl;

    replaceWithDesc(root);

    cout<<"After replacement:"<<endl;
    preorderTraversal(root);
    cout<<endl;
    return 0;
}