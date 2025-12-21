#include <bits/stdc++.h>
using namespace std;

/*
The solution here is to find the maximum number of non-overlapping intervals.
*/

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].second >> v[i].first;
    }

    sort(v.begin(), v.end());

    int ans = 0, last_end_time = -1;
    for (int i = 0; i < n; i++)
    {
        // If the start time of the current interval is greater than the last
        // interval, then this interval can be included in the answer set.
        if (v[i].second >= last_end_time)
        {
            ans++;
            last_end_time = v[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}