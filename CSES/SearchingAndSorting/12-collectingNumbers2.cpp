#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> v(n), idx(n + 2, -1);
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (idx[v[i] + 1] != -1)
            ans++;
        idx[v[i]] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        int x = v[a], y = v[b];
        set<int> s{x - 1, x, x + 1, y - 1, y, y + 1};

        int cont1 = 0;
        auto it1 = s.begin(), it2 = s.begin();
        it2++;
        for (; it2 != s.end(); it1++, it2++)
        {
            if (idx[*it1] > idx[*it2])
                cont1++;
        }

        int temp = v[a];
        v[a] = v[b], v[b] = temp;
        idx[x] = b, idx[y] = a;

        int cont2 = 0;
        it1 = s.begin(), it2 = s.begin();
        it2++;
        for (; it2 != s.end(); it1++, it2++)
        {
            if (idx[*it1] > idx[*it2])
                cont2++;
        }

        ans = ans - cont1 + cont2;
        cout << ans << endl;
    }
    return 0;
}