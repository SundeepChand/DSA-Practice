#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int i = 0, j = 1, ans = 1;
    // unordered_set<int> u; // This gives time limit exceeded. So use a set instead that gives guaranteed O(n * log n) time.
    set<int> u;
    u.insert(v[0]);

    while (j < n)
    {
        while (u.find(v[j]) != u.end())
        {
            u.erase(v[i]);
            i++;
        }
        u.insert(v[j]);
        j++;
        ans = max(ans, j - i);
    }
    cout << ans << endl;
    return 0;
}