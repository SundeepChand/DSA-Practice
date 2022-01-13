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
    vector<TreeNode *> pathS, pathD;
    void getPath(TreeNode *root, vector<TreeNode *> &path, int val, vector<TreeNode *> &p)
    {
        if (root == NULL)
            return;
        path.push_back(root);
        if (root->val == val)
        {
            p = path;
            return;
        }
        getPath(root->left, path, val, p);
        getPath(root->right, path, val, p);
        path.pop_back();
    }

    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        vector<TreeNode *> p;
        getPath(root, p, startValue, pathS);
        p.clear();
        getPath(root, p, destValue, pathD);

        int n = pathS.size(), m = pathD.size(), i = 0;
        for (i = 0; i < n && i < m; i++)
        {
            if (pathS[i] != pathD[i])
                break;
        }
        i--;
        string ans = "";
        // Traverse upwards first
        int j = n - 1;
        while (j != i)
            ans += "U", j--;
        while (i < m - 1)
        {
            if (pathD[i + 1] == pathD[i]->left)
                ans += "L";
            else if (pathD[i + 1] == pathD[i]->right)
                ans += "R";
            i++;
        }

        return ans;
    }
};