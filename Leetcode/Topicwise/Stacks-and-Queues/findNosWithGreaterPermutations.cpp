// https://www.geeksforgeeks.org/count-natural-numbers-whose-permutation-greater-number/
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef long long ll;
#define int ll

int solve(int n)
{
    queue<int> q;
    int ans = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (i <= n)
        {
            q.push(i);
            ans++;
        }

        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            for (int i = front % 10; i <= 9; i++)
            {
                int cur = 10 * front + i;
                if (cur <= n)
                {
                    q.push(cur);
                    ans++;
                }
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

    int n;
    cin >> n;

    auto start = high_resolution_clock::now();
    int ans = solve(n);
    auto stop = high_resolution_clock::now();
    cout << ans << endl;
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Took " << duration.count() << " ms" << endl;
    return 0;
}