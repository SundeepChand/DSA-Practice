#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

bool canMake(int rb, int rs, int rc, int nb, int ns, int nc, int pb, int ps, int pc, int r, int mid)
{
    int b = mid * rb, s = mid * rs, c = mid * rc;
    int price = max(0LL, b - nb) * pb + max(0LL, s - ns) * ps + max(0LL, c - nc) * pc;
    return price <= r;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    string recipe;
    cin >> recipe;
    int rb = 0, rs = 0, rc = 0;
    for (char c : recipe)
    {
        rb += (c == 'B');
        rs += (c == 'S');
        rc += (c == 'C');
    }

    int nb, ns, nc, pb, ps, pc, r;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;

    int lb = 0, ub = 1e13;
    int ans = 0;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (canMake(rb, rs, rc, nb, ns, nc, pb, ps, pc, r, mid))
        {
            lb = mid + 1;
            ans = mid;
        }
        else
            ub = mid - 1;
    }
    cout << ans << endl;
    return 0;
}