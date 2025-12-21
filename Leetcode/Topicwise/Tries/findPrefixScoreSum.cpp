#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    bool isLeaf;
    vector<TrieNode *> v1;
    vector<int> v2;

    TrieNode()
    {
        isLeaf = false;
        v1 = vector<TrieNode *>(26, NULL);
        v2 = vector<int>(26, 0);
    }
};

class Trie
{
public:
    TrieNode *root;
    int ans;

    Trie()
    {
        ans = 0;
        root = new TrieNode();
    }

    void insert(string &s)
    {
        TrieNode *cur = root;
        for (char c : s)
        {
            if (cur->v1[c - 'a'] == NULL)
                cur->v1[c - 'a'] = new TrieNode();
            cur->v2[c - 'a']++;
            cur = cur->v1[c - 'a'];
        }
        cur->isLeaf = true;
    }

    void sumUtil(TrieNode *root, int curSum)
    {
        if (root->isLeaf)
        {
            ans += curSum;
            return;
        }

        for (int i = 0; i < 26; i++)
        {
            if (root->v1[i] != NULL)
                sumUtil(root->v1[i], curSum + root->v2[i]);
        }
    }

    int sum()
    {
        sumUtil(root, 0);
        return ans;
    }
};

int solve(vector<string> &v, int k)
{
    Trie t;
    for (auto s : v)
        t.insert(s);

    return t.sum();
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << solve(v, k) << endl;
    return 0;
}