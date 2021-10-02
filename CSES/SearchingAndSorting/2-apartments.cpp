#include <bits/stdc++.h>
using namespace std;

/*
We sort the 2 arrays and find the solution by using an approach similar to the merge algorithm
*/

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> p(n), v(m);

    for (int i = 0; i < n; i++)
        cin >> p[i];

    for (int i = 0; i < m; i++)
        cin >> v[i];

    sort(p.begin(), p.end());
    sort(v.begin(), v.end());

    int i = 0, j = 0;
    int ans = 0;
    while (i < n && j < m)
    {
        if (abs(p[i] - v[j]) <= k)
        {
            i++;
            j++;
            ans++;
        }
        else if (p[i] < v[j])
        {
            i++;
        }
        else if (p[i] > v[j])
        {
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}