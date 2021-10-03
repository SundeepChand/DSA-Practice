#include <bits/stdc++.h>
using namespace std;

/*
// The hashmap based soln, exceeds the time-limit in certain TCs.
// This maybe because of a large number of collisions.

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    unordered_map<int, int> u;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        u[v[i]] = i;
    }

    int a = -1, b = -1;
    for (int i = 0; i < n; i++)
    {
        if (u.find(x - v[i]) != u.end() && u[x - v[i]] != i)
        {
            a = i + 1, b = u[x - v[i]] + 1;
            break;
        }
    }
    if (a != -1)
    {
        cout << a << " " << b << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
*/

int main()
{
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());

    // Let's try something like elimination after sorting
    int a = -1, b = -1;
    for (int i = 0, j = n - 1; i < j;)
    {
        int cur = v[i].first + v[j].first;
        if (cur < x)
            i++;
        else if (cur > x)
            j--;
        else
        {
            a = v[i].second + 1;
            b = v[j].second + 1;
            break;
        }
    }
    if (a != -1)
    {
        cout << a << " " << b << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}