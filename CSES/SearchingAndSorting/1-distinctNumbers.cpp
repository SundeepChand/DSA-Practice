#include <bits/stdc++.h>
using namespace std;

/*
Approach #1:
Sort the array and find the unique values. TC = O(n * log n), SC = O(1)

Approach #2:
We can store the values in a hash table & solve it in O(n) time & O(n) space.

But in the given problem, because of the values in the test-cases, the default hash function does not perform well
*/

int main()
{
    int n, ans = 1;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for (int i = 1; i < n; i++)
    {
        if (v[i] != v[i - 1])
            ans++;
    }

    cout << ans << endl;
    return 0;
}