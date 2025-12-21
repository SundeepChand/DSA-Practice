#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

class DSU
{
private:
    int n;
    vector<int> parent, rank;

public:
    DSU() : n(0) {}
    DSU(int n)
    {
        this->n = n;
        parent = vector<int>(n, -1);
        rank = vector<int>(n, 1);
    }

    int root(int n)
    {
        // int cur = n;
        // while (parent[cur] != -1)
        // {
        //     cur = parent[cur];
        // }
        // return cur;

        // Use a recursive implementation to easily apply path compression
        if (parent[n] == -1)
            return n;
        return parent[n] = root(parent[n]);
    }

    void Union(int u, int v)
    {
        int ru = root(u), rv = root(v);

        if (ru != rv)
        {
            if (rank[ru] < rank[rv])
            {
                parent[ru] = rv;
                rank[rv] += rank[ru];
            }
            else
            {
                parent[rv] = ru;
                rank[ru] += rank[rv];
            }
        }
    }

    bool find(int u, int v)
    {
        return (root(u) == root(v));
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

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<char> mp(26, 0);
        set<char> st;
        for (int i = 'a'; i <= 'z'; i++)
            st.insert(i);

        DSU d(26);
        int ctr = 0;

        string res = "";

        for (char c : s)
        {
            if (mp[c - 'a'] == 0)
            {
                for (char i = 'a'; i <= 'z'; i++)
                {
                    if (i != c and st.find(i) != st.end() and ((d.find(c - 'a', i - 'a') and ctr == 25) or !d.find(c - 'a', i - 'a')))
                    {
                        st.erase(i);
                        mp[c - 'a'] = i;
                        d.Union(c - 'a', i - 'a');
                        ctr++;
                        break;
                    }
                }
            }
            res += mp[c - 'a'];
        }
        cout << res << endl;
    }
    return 0;
}