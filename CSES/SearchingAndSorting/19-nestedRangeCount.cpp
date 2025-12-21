#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

/*
The approach mentioned here has O(n * log n) TC
We sort the intervals based on start/end times and based on that we
find how many elements are greater/less to the given element by storing it
inside an ordered multiset.
*/
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<pair<int, int>> v2(n), v1(n);
    vector<int> ans1(n, 0), ans2(n, 0);
    map<pair<int, int>, int> m;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v1[i] = {b, -a}; // The '-' is important to maintain the sorting order
        v2[i] = {a, -b}; // The '-' is important to maintain the sorting order
        m[{a, b}] = i;
    }

    // Find whether a range contains another range.
    sort(v1.begin(), v1.end());
    ordered_set st;
    for (int i = 0; i < n; i++)
    {
        int a = -v1[i].second, b = v1[i].first;
        int idx = m[{a, b}];
        // Find the count of intervals having start time greater than
        // the start time of the current interval.
        ans1[idx] = st.order_of_key(INT_MAX) - st.order_of_key(a);
        st.insert(a);
    }

    // Find whether a range is contained inside another range.
    sort(v2.begin(), v2.end());
    st = ordered_set();
    for (int i = 0; i < n; i++)
    {
        int a = v2[i].first, b = -v2[i].second;
        int idx = m[{a, b}];
        // Find the count of intervals having start time greater than
        // the start time of the current interval.
        ans2[idx] = st.order_of_key(INT_MAX) - st.order_of_key(b);
        st.insert(b);
    }

    // Print the answer
    for (int x : ans1)
        cout << x << " ";
    cout << endl;

    for (int x : ans2)
        cout << x << " ";
    cout << endl;
    return 0;
}