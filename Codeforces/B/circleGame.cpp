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

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        int minMike = 0, minJoe = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (i % 2 == 0)
            {
                if (v[i] < v[minMike])
                    minMike = i;
            }
            else
            {
                if (v[i] < v[minJoe])
                    minJoe = i;
            }
        }

        if (n % 2 == 0)
        {
            int moveMike = minMike / 2 + (n / 2) * v[minMike];

            int moveJoe = (minJoe - 1) / 2 + (n / 2) * v[minJoe];

            if (moveMike > moveJoe)
                cout << "Mike";
            else
                cout << "Joe";
        }
        else
        {
            cout << "Mike";
        }
        cout << endl;
    }
    return 0;
}