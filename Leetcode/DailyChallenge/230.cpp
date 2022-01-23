#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<int> v;
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root);
        return v[k - 1];
    }
};

class Solution1
{
public:
    unordered_map<TreeNode *, int> u;
    int getSize(TreeNode *root, int offset)
    {
        if (root == NULL)
            return 0;
        int left = getSize(root->left, offset);
        int right = getSize(root->right, offset + 1 + left);
        u[root] = 1 + left + offset;
        return 1 + left + right;
    }

    int kthSmallest(TreeNode *root, int k)
    {
        getSize(root, 0);

        TreeNode *cur = root;
        while (u[cur] != k)
        {
            if (u[cur] < k)
                cur = cur->right;
            else if (u[cur] > k)
                cur = cur->left;
        }

        return cur->val;
    }
};