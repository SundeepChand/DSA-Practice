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


int main()
{
    Node* head = buildTree();

    cout<<"\nPreorder traversal of tree"<<endl;
    preorderTraversal(head);
    cout<<endl;
    return 0;
}