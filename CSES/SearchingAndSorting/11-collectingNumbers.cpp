#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n), idx(n + 1, -1);
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i]--;
        if (idx[v[i] + 1] != -1)
            ans++;
        idx[v[i]] = i;
    }
    cout << ans << endl;
    return 0;
}