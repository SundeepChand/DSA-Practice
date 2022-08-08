#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

string solve(string &st, int i, int sum)
{
    int n = st.size();
    if (sum == 0)
        return "s";
    if (i >= n)
        return "";

    string ans = "";
    for (int j = i; j < n; j++)
    {
        if (st[j] - '0' <= sum)
        {
            string subProb = solve(st, j + 1, sum - st[j] + '0');
            if (subProb != "")
            {
                ans += subProb;
                ans += st[j];
                break;
            }
        }
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
        int s;
        cin >> s;

        string st = "987654321";
        string ans = solve(st, 0, s);
        cout << ans.substr(1) << endl;
    }
    return 0;
}