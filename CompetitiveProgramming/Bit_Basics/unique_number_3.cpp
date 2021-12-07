#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

int findUnique3(vector<int> v)
{
    vector<int> freq(32, 0);

    for (int x : v)
    {
        int i = 31;
        while (x)
        {
            if (x & 1)
            {
                freq[i]++;
            }
            x >>= 1;
            i--;
        }
    }

    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        ans <<= 1;
        if (freq[i] % 3 == 1)
        {
            ans |= 1;
        }
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << findUnique3(a) << endl;

    return 0;
}