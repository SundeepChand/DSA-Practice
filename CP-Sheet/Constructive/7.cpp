#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

void printCompleteRow(int n)
{
    string s(n, '#');
    cout << s << endl;
}

void printOneCell(int n, bool dir)
{
    string s(n, '.');
    if (dir)
        s[0] = '#';
    else
        s[n - 1] = '#';
    cout << s << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    printCompleteRow(m);

    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 1)
            printOneCell(m, (i / 2) % 2);
        else
            printCompleteRow(m);
    }
    return 0;
}