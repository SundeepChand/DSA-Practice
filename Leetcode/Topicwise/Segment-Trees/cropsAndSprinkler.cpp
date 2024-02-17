#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

#define MAX_SIZE 200000

vector<ordered_set> st(4 * MAX_SIZE);

void buildSegmentTree(vector<int> &arr, int cur, int tl, int tr)
{
    if (tl == tr)
    {
        st[cur].insert(arr[tl]);
        return;
    }
    int tm = tl + (tr - tl) / 2;
    int left = 2 * cur + 1, right = 2 * cur + 2;

    buildSegmentTree(arr, left, tl, tm);
    buildSegmentTree(arr, right, tm + 1, tr);

    for (auto x : st[left])
        st[cur].insert(x);
    for (auto x : st[right])
        st[cur].insert(x);
}

int getLessCrops(int cur, int l, int r, int tl, int tr, int w)
{
    // cout << "DEB: " << l << " " << r << endl;
    if (l > r)
    {
        return 0;
    }
    if (l == tl and r == tr)
    {
        int val = st[cur].order_of_key(w);
        // Delete all keys less than w ??
        return val;
    }

    int tm = tl + (tr - tl) / 2;
    int left = 2 * cur + 1, right = 2 * cur + 2;
    return getLessCrops(left, l, min(tm, r), tl, tm, w) + getLessCrops(right, max(l, tm + 1), r, tm + 1, tr, w);
}

int updateCropLand(int cur, int tl, int tr, int c, int idx)
{
    if (tl == idx and tr == idx)
    {
        int prev = *(st[cur].begin());
        st[cur].clear();
        st[cur].insert(c);
        return prev;
    }

    int left = 2 * cur + 1, right = 2 * cur + 2;
    int tm = tl + (tr - tl) / 2, prev = INT_MAX;

    if (idx <= tm)
        prev = updateCropLand(left, tl, tm, c, idx);
    else if (idx > tm)
        prev = updateCropLand(right, tm + 1, tr, c, idx);

    st[cur].erase(st[cur].find(prev));
    st[cur].insert(c);
    return prev;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;

    vector<int> land(n, 100);
    buildSegmentTree(land, 0, 0, n - 1);
    cout << "DEB: " << n << " " << k << endl;

    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int idx, c;
            cin >> idx >> c;
            updateCropLand(0, 0, n - 1, c, idx);
        }
        else
        {
            int l, r, w;
            cin >> l >> r >> w;
            r--;

            ans.push_back(getLessCrops(0, l, r, 0, n - 1, w + 1));
        }

        // if (i == 3)
        // {
        //     for (auto x : st)
        //     {
        //         for (auto y : x)
        //             cout << y << " ";
        //         cout << endl;
        //     }
        //     cout << endl;
        // }
    }

    cout << "Ans = ";
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}