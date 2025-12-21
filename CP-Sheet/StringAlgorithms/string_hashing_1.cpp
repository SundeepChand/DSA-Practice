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
    vector<TrieNode *> v;

    TrieNode()
    {
        v = vector<TrieNode *>(26, NULL);
    }
};

void solveUsingTrie(const string &s, const string &mask, const int &k)
{
    int n = s.size();
    int ans = 0;

    TrieNode *root = new TrieNode();

    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        TrieNode *curNode = root;
        bool flag = false;
        for (int j = i; cur <= k and j < n; j++)
        {
            if (!(mask[s[j] - 'a'] - '0'))
                cur++;
            if (cur > k)
                break;

            if (curNode->v[s[j] - 'a'] == NULL)
            {
                curNode->v[s[j] - 'a'] = new TrieNode();
                flag = true;
            }
            curNode = curNode->v[s[j] - 'a'];
            if (flag)
                ans++;
        }
    }

    cout << ans << endl;
}

void solveUsingRollingHash(const string &s, const string &mask, const int &k)
{
    int n = s.size();

    int p1 = 31, m1 = 1e9 + 9, p2 = 27, m2 = 1e9 + 7; // Can change p and/or m.
    set<pair<int, int>> st;

    for (int i = 0; i < n; i++)
    {
        int hash1 = 0, hash2 = 0, cur = 0;
        for (int j = i; cur <= k and j < n; j++)
        {
            if (!(mask[s[j] - 'a'] - '0'))
                cur++;
            if (cur > k)
                break;
            hash1 = ((p1 * hash1) % m1 + (s[j] - 'a' + 1)) % m1;
            hash2 = ((p2 * hash2) % m2 + (s[j] - 'a' + 1)) % m2;
            st.insert({hash1, hash2});
        }
    }

    cout << st.size() << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    string s;
    cin >> s;

    string mask;
    cin >> mask;

    int k;
    cin >> k;

    solveUsingRollingHash(s, mask, k);
    return 0;
}