#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

map<int, int> divisors(int n)
{
    map<int, int> m;
    for (int i = 2; i * i <= n; i++)
    {
        int ctr = 0;
        while (n % i == 0)
            n /= i, ctr++;
        if (ctr > 0)
            m[i] = ctr;
    }
    if (n > 1)
        m[n] = 1;
    return m;
}

vector<int> solve(int n)
{
    map<int, int> div = divisors(n);
    if (div.size() == 1)
    {
        return {n, 0};
    }
    int val = 1, max_exp = 0, ctr = 0;
    for (auto it = div.begin(); it != div.end(); it++)
    {
        val *= it->first;
        if (it->second > max_exp)
        {
            max_exp = it->second;
            ctr++;
        }
        else if (it->second < max_exp)
            ctr++;
    }
    return {val, (int)ceil(log2(double(max_exp))) + (ctr > 1)};
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

    vector<int> v = solve(n);
    cout << v[0] << " " << v[1] << endl;
    return 0;
}