#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

class TrieNode
{
public:
    vector<TrieNode *> nbrs;
    bool isLeaf;
    int nEdges;

    TrieNode()
    {
        nEdges = 26;
        nbrs = vector<TrieNode *>(nEdges, NULL);
        isLeaf = false;
    }
};

class Trie
{
    // Modified version of trie used for pattern matching
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string s)
    {
        TrieNode *cur = root;
        for (int i = 0; i < s.length(); i++)
        {
            int idx = s[i] - 'a';
            if (cur->nbrs[idx] == NULL)
                cur->nbrs[idx] = new TrieNode();
            cur = cur->nbrs[idx];
        }
        cur->isLeaf = true;
    }

    bool search(string s)
    {
        TrieNode *cur = root;
        for (int i = 0; i < s.length(); i++)
        {
            int idx = s[i] - 'a';
            if (cur->nbrs[idx] == NULL)
                return false;
            cur = cur->nbrs[idx];
        }
        // return cur->isLeaf;
        return true;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    Trie t;
    string text, pat;
    cin >> text >> pat;

    int n = text.size();

    string suffix = "";
    for (int i = n - 1; i >= 0; i--)
    {
        suffix.insert(0, 1, text[i]);
        t.insert(suffix);
    }

    cout << t.search(pat) << endl;

    return 0;
}