#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

void partition(vector<int> &v, int s, int e)
{
    int pivot = s;
    int l = s, r = e, cur = s + 1;
    while (cur <= r)
    {
        if (v[cur] < v[l])
        {
            swap(v[cur], v[l]);
            l++;
        }
        else if (v[cur] > v[l])
        {
            swap(v[cur], v[r]);
            r--;
            cur--;
        }
        cur++;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    partition(v, 0, n - 1);
    for (auto x : v)
        cout << x << " ";
    cout << endl;
    return 0;
}