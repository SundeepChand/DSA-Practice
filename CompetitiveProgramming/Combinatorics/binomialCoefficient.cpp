#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

vector<vector<int>> binomCoeff;

void initBinomCoeff(int n)
{
    binomCoeff = vector<vector<int>>(n + 1, vector<int>(n + 1));

    binomCoeff[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        binomCoeff[i][0] = binomCoeff[i][i] = 1;
        for (int j = 1; j < i; j++)
            binomCoeff[i][j] = binomCoeff[i - 1][j] + binomCoeff[i - 1][j - 1];
    }
}

int nCr(int n, int r)
{
    return binomCoeff[n][r];
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

    initBinomCoeff(10);

    cout << nCr(3, 2) << endl;
    cout << nCr(4, 2) << endl;
    cout << nCr(4, 3) << endl;
    cout << nCr(5, 5) << endl;
    cout << nCr(5, 3) << endl;
    cout << nCr(5, 2) << endl;
    cout << nCr(8, 0) << endl;

    return 0;
}