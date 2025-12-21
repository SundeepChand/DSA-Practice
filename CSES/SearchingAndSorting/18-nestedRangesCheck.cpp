#include <bits/stdc++.h>
using namespace std;

/*
The approach mentioned here has O(n * log n) TC
We sort the intervals based on start/end times and based on that we
find how many elements are greater/less to the given element.
*/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<pair<int, int>> v2(n), v1(n);
    vector<bool> ans1(n, 0), ans2(n, 0);
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
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int a = -v1[i].second, b = v1[i].first;
        if (st.lower_bound(a) != st.end())
        {
            int idx = m[{a, b}];
            ans1[idx] = 1;
        }
        st.insert(a);
    }

    // Find whether a range is contained in another range.
    sort(v2.begin(), v2.end());
    st = set<int>();
    for (int i = 0; i < n; i++)
    {
        int a = v2[i].first, b = -v2[i].second;
        if (st.lower_bound(b) != st.end())
        {
            int idx = m[{a, b}];
            ans2[idx] = 1;
        }
        st.insert(b);
    }

    // Print the answer
    for (bool x : ans1)
        cout << x << " ";
    cout << endl;

    for (bool x : ans2)
        cout << x << " ";
    cout << endl;

    return 0;
}

/*
// Another approach
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

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

    vector<vector<int>> v1(n, vector<int>(3));
    vector<vector<int>> v2(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> v2[i][0] >> v2[i][1];
        v2[i][1] *= -1;
        v1[i][0] = -v2[i][1], v1[i][1] = -v2[i][0];
        v1[i][2] = v2[i][2] = i;
    }

    sort(v1.begin(), v1.end());
    vector<bool> ans1(n, 0);
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int curEnd = v1[i][0], curStart = -v1[i][1];
        if (st.lower_bound(curStart) != st.end())
            ans1[v1[i][2]] = 1;
        st.insert(curStart);
    }

    sort(v2.begin(), v2.end());
    int maxEnd = 0;
    vector<bool> ans2(n, 0);

    for (int i = 0; i < n; i++)
    {
        int curEnd = -v2[i][1];
        if (curEnd <= maxEnd)
        {
            ans2[v2[i][2]] = 1;
        }
        maxEnd = max(maxEnd, curEnd);
    }

    for (auto x : ans1)
    {
        cout << x << " ";
    }
    cout << endl;

    for (auto x : ans2)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

*/