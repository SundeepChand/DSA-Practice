// Solution of https://leetcode.com/discuss/interview-question/4739123/Google-L4-VO-coding-question
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"
#define NULL_NODE "N"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode *parent;

    TreeNode(int n);
    TreeNode(int n, TreeNode *parent);
};

TreeNode::TreeNode(int n) {
    this->val = n;
    this->left = this->right = this->parent = NULL;
}

TreeNode::TreeNode(int n, TreeNode *parent) {
    this->val = n;
    this->parent = parent;
    this->left = this->right = NULL;
}

TreeNode* buildTree(const vector<string> &v) {
    TreeNode* root = NULL;

    if (v.size() <= 0 or v[0] == NULL_NODE) {
        return root;
    }

    int n = v.size();
    queue<TreeNode*> q;
    for (int i = 0; i < n; i++) {
        if (root == NULL) {
            root = new TreeNode(stoi(v[i]));
            q.push(root);
            continue;
        }

        auto front = q.front();
        q.pop();

        if (v[i] != NULL_NODE) {
            front->left = new TreeNode(stoi(v[i]), front);
            q.push(front->left);
        }
        i++;
        if (i < n and v[i] != NULL_NODE) {
            front->right = new TreeNode(stoi(v[i]), front);
            q.push(front->right);
        }
    }

    return root;
}

void levelOrderTraversal(TreeNode *root) {
    queue<TreeNode*> q;

    q.push(root);

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        cout<<(front->val)<<" ";

        if (front->left != NULL) {
            q.push(front->left);
        }
        if (front->right != NULL) {
            q.push(front->right);
        }
    }
    cout<<endl;
}

void printLeafDeletionOrderUtil(TreeNode *root) {
    if (root == NULL) {
        return;
    }

    printLeafDeletionOrderUtil(root->left);
    printLeafDeletionOrderUtil(root->right);
    cout<<root->val<<" ";
}

void printLeafDeletionOrder(TreeNode *root) {
    printLeafDeletionOrderUtil(root);
    cout<<endl;
}

set<TreeNode*> getAllLeafNodes(TreeNode *root) {
    set<TreeNode*> res;
    if (root == NULL) {
        return res;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        if (front->left == NULL and front->right == NULL) {
            res.insert(front);
        }

        if (front->left != NULL) {
            q.push(front->left);
        }
        if (front->right != NULL) {
            q.push(front->right);
        }
    }

    return res;
}

void printAllSolutionsUtil(set<TreeNode*> &leaves, vector<TreeNode*> &cur, vector<vector<TreeNode*>> &ans) {
    int n = leaves.size();

    if (leaves.size() == 0) {
        return;
    }

    set<TreeNode*> newLeaves = leaves;

    for (auto it = leaves.begin(); it != leaves.end(); it++) {
        cur.push_back(*it);
        if ((*it)->parent == NULL) {
            ans.push_back(cur);
            cur.pop_back();
            continue;
        }

        newLeaves.erase(*it);
        bool left = false, right = false;
        if ((*it)->parent->left == *it) {
            (*it)->parent->left = NULL;
            left = true;
        }
        if ((*it)->parent->right == *it) {
            (*it)->parent->right = NULL;
            right = true;
        }
        if ((*it)->parent->left == NULL && (*it)->parent->right == NULL) {
            newLeaves.insert((*it)->parent);
        }
        printAllSolutionsUtil(newLeaves, cur, ans);
        cur.pop_back();
        newLeaves.insert(*it);
        newLeaves.erase((*it)->parent);

        if (left) {
            (*it)->parent->left = *it;
        }
        if (right) {
            (*it)->parent->right = *it;
        }
    }
}

void printAllSolutions(TreeNode *root) {
    set<TreeNode*> leaves = getAllLeafNodes(root);

    vector<vector<TreeNode*>> ans;
    vector<TreeNode*> cur;

    printAllSolutionsUtil(leaves, cur, ans);

    for (auto arr: ans) {
        for (auto ele: arr) {
            cout<<ele->val<<" ";
        }
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    TreeNode* root = buildTree(v);

    cout<<"Level order of tree: ";
    levelOrderTraversal(root);
    cout<<endl;

    cout<<"Leaf deletion order of tree: ";
    // Solve part 1
    printLeafDeletionOrder(root);
    cout<<endl;

    cout<<"Solutions for leaf deletions:"<<endl;
    // Solve part 2
    printAllSolutions(root);
    cout<<endl;

    return 0;
}