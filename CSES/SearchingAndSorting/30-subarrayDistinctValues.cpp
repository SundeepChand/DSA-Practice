#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll ans = 0;
    int i = -1, j = 0;
    map<int, int> s;
    while (i < n)
    {
        if (s.size() > k)
        {
            s[v[j]]--;
            if (s[v[j]] == 0)
                s.erase(v[j]);
            j++;
        }
        else
        {
            i++;
            if (i < n)
            {
                s[v[i]]++;
            }
            else
                break;
        }
        if (s.size() <= k)
        {
            ll x = i - j + 1;
            ans += x;
        }
    }

    cout << ans << endl;
    return 0;
}