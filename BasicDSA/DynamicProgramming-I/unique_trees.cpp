#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void preorder(TreeNode* root)
{
    if (root == NULL)
    {
        cout<<"NULL, ";
        return;
    }
    cout<<root->val<<", ";
    preorder(root->left);
    preorder(root->right);
}

class Solution {
public:
    vector<TreeNode*> solve(vector<int> &v, int i, int j)
    {
        if (j - i < 0)
            return {NULL};
        
        vector<TreeNode*> ans;
        for (int x = i; x <= j; x++)
        {
            vector<TreeNode*> left = solve(v, i, x - 1);
            vector<TreeNode*> right = solve(v, x + 1, j);
            for (int y = 0; y < left.size(); y++)
            {
                for (int z = 0; z < right.size(); z++)
                {
                    TreeNode* root = new TreeNode(v[x]);
                    root->left = left[y];
                    root->right = right[z];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = i + 1;
        }
        
        vector<TreeNode*> ans = solve(v, 0, n - 1);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<TreeNode*> ans = s.generateTrees(3);

    for (auto x: ans)
    {
        preorder(x);
        cout<<endl;
    }
    return 0;
}