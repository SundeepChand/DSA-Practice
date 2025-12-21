#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

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
        string n;
        cin>>n;

        int sum = 0;
        for (char c: n)
        {
            sum += (c - '0');
        }

        int d = (9 - (sum % 9)) % 9;
        cout<<"Case #"<<(tc - t)<<": ";
        if (d == 0)
        {
            cout<<n[0]<<d<<n.substr(1)<<endl;
            continue;
        }
        string pref = "";
        int i = 0;
        for (; i < n.length(); i++)
        {
            if (d + '0' < n[i])
            {
                break;
            }
            pref += n[i];
        }

        
        cout<<pref<<d<<n.substr(i)<<endl;
    }
    return 0;
}