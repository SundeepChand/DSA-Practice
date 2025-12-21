#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    int ctr = 0;
    for (int i = 0; i < n; i++)
    {
        int vert = 0, h = 0;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                if (v[i].first == v[j].first && v[i].second > v[j].second)
                {
                    vert |= 1;
                }
                else if (v[i].first == v[j].first && v[i].second < v[j].second)
                {
                    vert |= 2;
                }

                if (v[i].second == v[j].second && v[i].first > v[j].first)
                {
                    h |= 1;
                }
                else if (v[i].second == v[j].second && v[i].first < v[j].first)
                {
                    h |= 2;
                }
            }
        }
        if (h == 3 && vert == 3)
        {
            ctr++;
        }
    }
    cout << ctr << endl;
    return 0;
}