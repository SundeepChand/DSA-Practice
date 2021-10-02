#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int i = 0, j = n - 1;
    int ans = 0;
    while (i <= j)
    {
        ans++;
        if (v[i] + v[j] <= x)
        {
            i++;
            j--;
        }
        else
        {
            j--;
        }
    }
    cout << ans << endl;
    return 0;
}