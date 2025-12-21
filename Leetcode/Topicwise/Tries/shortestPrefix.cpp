#include <bits/stdc++.h>
using namespace std;

class Solution
{
    class TrieNode
    {
    public:
        map<char, TrieNode *> v;
        short int nChildren;

        TrieNode()
        {
            nChildren = 0;
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

        void insert(const string &s)
        {
            TrieNode *cur = root;
            for (char c : s)
            {
                (cur->nChildren)++;
                if ((cur->v).find(c) == (cur->v).end())
                    cur->v[c] = new TrieNode();
                cur = cur->v[c];
            }
            (cur->nChildren)++;
        }

        void getSmallestPrefix(const string &s, string &res)
        {
            TrieNode *cur = root;
            for (int i = 0; cur != NULL and i < s.size(); i++)
            {
                char c = s[i];
                if (cur->nChildren == 1)
                    break;
                res += c;
                cur = cur->v[c];
            }
        }
    };

public:
    vector<string> findPrefixes(string arr[], int n)
    {
        vector<string> ans;
        if (n == 1)
        {
            string res = "";
            res += arr[0][0];
            ans.push_back(res);
            return ans;
        }

        Trie t;
        for (int i = 0; i < n; i++)
        {
            t.insert(arr[i]);
        }

        for (int i = 0; i < n; i++)
        {
            string res = "";
            t.getSmallestPrefix(arr[i], res);
            ans.push_back(res);
        }
        return ans;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    string arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution s;
    vector<string> res = s.findPrefixes(arr, n);
    for (auto pre : res)
    {
        cout << pre << endl;
    }

    return 0;
}