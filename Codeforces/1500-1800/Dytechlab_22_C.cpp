#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int getCenter(int r[], int c[])
{
    int dist = abs(r[0] - r[1]) + abs(c[0] - c[1]);
    if (dist == 2)
        return 2;

    dist = abs(r[0] - r[2]) + abs(c[0] - c[2]);
    if (dist == 2)
        return 1;

    return 0;
}

bool isOnCorner(int n, int r, int c)
{
    return (r == 1 and c == 1) or (r == 1 and c == n) or (r == n and c == 1) or (r == n and c == n);
}

bool canSolve(int n, int r[], int c[], int x, int y)
{
    int centerIdx = getCenter(r, c);
    bool flag = false;

    if (isOnCorner(n, r[centerIdx], c[centerIdx]))
    {
        flag = flag or c[centerIdx] - y == 0 or r[centerIdx] - x == 0;
    }
    else
    {
        // for (int i = 0; i < 3; i++)
        // {
        //     flag = flag or (abs(r[i] - x) % 2 == 0 and abs(c[i] - y) % 2 == 0);
        // }
        if (abs(r[centerIdx] - x) % 2 == 1)
        {
            if (abs(c[centerIdx] - y) % 2 == 0)
                flag = true;
        }
        else
            flag = true;
    }
    return flag;
}

void visualize()
{
    int N = 6;
    int r[] = {6, 6, 5};
    int c[] = {1, 2, 1};

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (canSolve(N, r, c, i, j))
                cerr << "@ ";
            else
                cerr << ". ";
        }
        cerr << endl;
    }
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
        cin >> n;

        int r[3], c[3];
        cin >> r[0] >> c[0] >> r[1] >> c[1] >> r[2] >> c[2];

        int x, y;
        cin >> x >> y;

        if (canSolve(n, r, c, x, y))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}