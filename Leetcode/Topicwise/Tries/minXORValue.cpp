#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *edges[2];

    TrieNode()
    {
        edges[0] = edges[1] = NULL;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    int insert(int val)
    {
        int xr = 0;
        TrieNode *cur = root, *xr_cur = root;
        for (int i = 30; i >= 0; i--)
        {
            int bit = (val >> i) & 1;

            if (xr_cur->edges[bit] == NULL)
                xr |= (1 << i), xr_cur = xr_cur->edges[!bit];
            else
                xr_cur = xr_cur->edges[bit];

            if (cur->edges[bit] == NULL)
                cur->edges[bit] = new TrieNode();
            cur = cur->edges[bit];
        }
        return xr;
    }
};

int findMinXor(vector<int> &A)
{
    int n = A.size();
    int ans = INT_MAX;
    Trie t;
    t.insert(A[0]);
    for (int i = 1; i < n; i++)
    {
        ans = min(ans, t.insert(A[i]));
    }
    return ans;
}
