#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

bool canSolve(map<char, int> m, int x, int k)
{
    vector<int> v;
    for (auto x : m)
    {
        v.push_back(x.second);
    }
    while (k > 0)
    {
        sort(v.begin(), v.end(), greater<int>());
        if (v[0] <= 0)
            return false;
        int cur_size = 0;
        if (x % 2 == 1)
        {
            bool hasodd = false;
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] % 2 == 1)
                {
                    cur_size++, v[i]--;
                    hasodd = true;
                    break;
                }
            }
            if (!hasodd)
                cur_size++, v[0]--;
        }
        while (cur_size < x)
        {
            sort(v.begin(), v.end(), greater<int>());
            if (v[0] <= 0)
                return false;
            // Pick 2 elements from map
            if (v[0] < 2)
                return false;
            cur_size += 2;
            v[0] -= 2;
        }
        k--;
    }
    return true;
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
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        map<char, int> m;
        for (char c : s)
        {
            m[c]++;
        }

        int lb = 1, ub = n;
        int ans = 1;
        while (lb <= ub)
        {
            int mid = (lb + ub) / 2;
            if (canSolve(m, mid, k))
            {
                ans = mid;
                lb = mid + 1;
            }
            else
                ub = mid - 1;
        }
        cout << ans << endl;
    }
    return 0;
}