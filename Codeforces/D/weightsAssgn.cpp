#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

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

        vector<int> b(n), p(n);
        vector<vector<int>> adj(n, vector<int>());
        int root = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            b[i]--;
            if (b[i] != i)
            {
                adj[b[i]].push_back(i);
                adj[i].push_back(b[i]);
            }
            else
                root = i;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            p[i]--;
        }

        set<int> s;
        s.insert(root);
        vector<int> dist(n, 0);
        int ctr = 1, sz = 1;
        int i = 0;
        bool flag = true;
        if (p[0] != root)
            flag = false;
        else
        {
            while (i < n && !s.empty())
            {
                auto it = s.find(p[i]);
                if (it == s.end())
                {
                    flag = false;
                    break;
                }
                int node = *it;
                s.erase(it);
                i++;

                dist[node] = ctr;
                ctr++;
                for (int nbr : adj[node])
                {
                    if (nbr != b[nbr])
                    {
                        s.insert(nbr);
                        sz++;
                    }
                }
            }
            if (i < n)
            {
                flag = false;
            }
        }

        if (!flag)
            cout << -1;
        else
        {
            for (int i = 0; i < n; i++)
                cout << (dist[i] - dist[b[i]]) << " ";
        }
        cout << endl;
    }
    return 0;
}