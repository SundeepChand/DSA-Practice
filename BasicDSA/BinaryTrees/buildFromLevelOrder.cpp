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

void inorderTraversal(Node* cur)
{
    if (cur == NULL)
        return;

    inorderTraversal(cur->left);
    cout<<cur->data<<", ";
    inorderTraversal(cur->right);
}

int main()
{
    vector<int> input = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7, -1, -1, -1, -1, -1};
    // vector<int> input = {1, 2, 3, -1, -1, 4, -1, -1, 5};
    int n = input.size();

    Node* head = new Node(input[0]);

    queue<Node*> q;
    q.push(head);

    int i = 1;
    while (!q.empty())
    {
        Node* top = q.front();
        q.pop();

        int left = i, right = i + 1;
        // cout<<top->data<<", "<<left<<", "<<right<<endl;
        i += 2;
        if (left < n)
        {
            int val = input[left];
            if (val != -1)
            {
                Node *newNode = new Node(val);
                top->left = newNode;
                q.push(newNode);
            }
        }
        if (right < n)
        {
            int val = input[right];
            if (val != -1)
            {
                Node *newNode = new Node(val);
                top->right = newNode;
                q.push(newNode);
            }
        }
    }

    cout<<"Final tree:"<<endl;
    inorderTraversal(head);
    cout<<endl;
    return 0;
}