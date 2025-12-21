#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

bool check(int i)
{
    int prod = 1, sum = 0;
    while (i)
    {
        int d = i % 10;
        prod *= d, sum += d;
        i /= 10;
    }
    return prod % sum == 0;
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
    int tc = t;

    while (t--)
    {
        int a, b;
        cin>>a>>b;

        int ctr = 0;
        for (int i = a; i <= b; i++)
        {
            if (check(i))
                ctr++;
        }
        cout<<"Case #"<<(tc - t)<<": "<<ctr<<endl;
    }
    return 0;
}