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

class Solution {
public:
    vector<int> ans;
    
    void findAtDistK(Node* root, int k)
    {
        if (root == NULL || k < 0)
            return;
        if (k == 0)
        {
            ans.push_back(root->val);
            return;
        }
        findAtDistK(root->left, k - 1);
        findAtDistK(root->right, k - 1);
    }
    
    int solve(Node* root, Node* target, int k)
    {
        if (root == NULL)
            return -1;
        
        if (root == target)
        {
            findAtDistK(root, k);
            return 0;
        }
        
        int dl = solve(root->left, target, k);
        if (dl != -1)
        {
            if (dl + 1 == k)
            {
                ans.push_back(root->val);
            }
            else if (dl < k - 1)
            {
                findAtDistK(root->right, k - dl - 2);
            }
            return dl + 1;
        }
        int dr = solve(root->right, target, k);
        if (dr != -1)
        {
            if (dr + 1 == k)
            {
                ans.push_back(root->val);
            }
            else if (dr < k - 1)
            {
                findAtDistK(root->left, k - dr - 2);
            }
            return dr + 1;
        }
        return -1;
    }
    
    vector<int> distanceK(Node* root, Node* target, int k) {
        solve(root, target, k);
        return ans;
    }
};

int main()
{
    Node *root = new Node(0);
    root->right = new Node(1);
    root->right->right = new Node(2);
    root->right->right->right = new Node(3);

    Solution s;
    vector<int> ans = s.distanceK(root, root->right, 2);
    for (auto x: ans)
        cout<<x<<", ";
    return 0;
}