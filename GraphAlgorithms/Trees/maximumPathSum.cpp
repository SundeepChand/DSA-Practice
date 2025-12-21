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
    pair<int, int> solve(TreeNode *root)
    {
        if (root == NULL)
            return {0, 0};
        if (root->left == NULL && root->right == NULL)
            return {root->val, root->val};
        if (root->right == NULL)
        {
            pair<int, int> left = solve(root->left);
            int ans = max({left.first + root->val, left.second, root->val});
            int path = max({left.first + root->val, root->val});
            return {path, ans};
        }
        if (root->left == NULL)
        {
            pair<int, int> right = solve(root->right);
            int ans = max({right.first + root->val, right.second, root->val});
            int path = max({right.first + root->val, root->val});
            return {path, ans};
        }

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        int ans = max({left.first + right.first + root->val, left.second, right.second, left.first + root->val, right.first + root->val, root->val});
        int path = max({left.first + root->val, right.first + root->val, root->val});
        return {path, ans};
    }
    int maxPathSum(TreeNode *root)
    {
        return solve(root).second;
    }
};