#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int maxTries(int p, int q)
{
    return floor(1 + log2((long double)q));
}

int solve(string &s1, string &s2)
{
    int n1 = s1.length(), n2 = s2.length();

    int i = n1 - 1, j = n2 - 1;
    while (j >= 0 && s2[j] > s1[i])
        j--;
    if (j < 0)
        return 0;

    int ans = j + 1;
    while (i >= 0 && s1[i] == 'z')
        ans++, i--;
    return ans;
}

int minimumNumberOfOperations(string s1, string s2)
{
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    int n1 = solve(s1, s2), n2 = solve(s2, s1);

    vector<int> f1(26, 0), f2(26, 0);
    for (auto x : s1)
    {
        f1[x - 'a']++;
    }
    for (auto x : s2)
    {
        f2[x - 'a']++;
    }
    int n = s1.length(), m = s2.length();
    int n3 = n + m;
    for (int i = 0; i < 26; i++)
    {
        n3 = min(n3, n + m - f1[i] - f2[i]);
    }

    // cout << n1 << " " << n2 << " " << n3 << endl;

    int ans = min({n1, n2, n3});
    return ans;
}

int sendWagons(int limit, vector<int> &v)
{
    int n = v.size();
    sort(v.begin(), v.end());

    int ans = 0;
    int i = 0, j = n - 1;
    while (i <= j)
    {
        ans++;
        if (v[j] + v[i] <= limit)
            j--, i++;
        else
            j--;
    }
    return ans;
}

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
        int limit;
        cin >> n >> limit;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        cout << sendWagons(limit, v) << endl;
    }
    return 0;
}