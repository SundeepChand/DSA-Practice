#include <bits/stdc++.h>
using namespace std;

/*
The solution is to find the maximum number of overlapping intervals.
*/

int main()
{
    int n;
    cin >> n;

    vector<pair<int, bool>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, 0}); // 0 denotes arrival time
        v.push_back({b, 1}); // 1 denotes leaving time
    }

    sort(v.begin(), v.end());

    int ans = 0, ctr = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].second == 0)
        {
            ctr++;
        }
        else
        {
            ctr--;
        }
        ans = max(ans, ctr);
    }
    cout << ans << endl;
    return 0;
}