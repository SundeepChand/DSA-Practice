#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:
    vector<int> st;
    int n;

    SegmentTree(const vector<int> &arr)
    {
        n = arr.size();

        st = vector<int>(4 * n, 0);

        buildTree(arr, 0, 0, n - 1);
    }

    void buildTree(const vector<int> &arr, int cur, int tl, int tr)
    {
        if (tl == tr)
        {
            st[cur] = arr[tl];
            return;
        }
        int mid = tl + (tr - tl) / 2;
        buildTree(arr, 2 * cur + 1, tl, mid);
        buildTree(arr, 2 * cur + 2, mid + 1, tr);
        st[cur] = st[2 * cur + 1] + st[2 * cur + 2];
    }

    int getSumUtil(int cur, int tl, int tr, int l, int r)
    {
        // cout << "DEB: " << l << " " << r << endl;
        if (l > r)
            return 0;
        if (l == tl and r == tr)
            return st[cur];

        int tm = tl + (tr - tl) / 2;
        return getSumUtil(2 * cur + 1, tl, tm, l, min(r, tm)) + getSumUtil(2 * cur + 2, tm + 1, tr, max(l, tm + 1), r);
    }

    int getSum(int l, int r)
    {
        return getSumUtil(0, 0, n - 1, l, r);
    }

    void updateUtil(int cur, int tl, int tr, int val, int idx)
    {
        if (tl == idx and tr == idx)
        {
            st[cur] = val;
            return;
        }

        int tm = tl + (tr - tl) / 2;
        if (idx <= tm)
            updateUtil(2 * cur + 1, tl, tm, val, idx);
        else
            updateUtil(2 * cur + 2, tm + 1, tr, val, idx);
        st[cur] = st[2 * cur + 1] + st[2 * cur + 2];
    }

    void update(int val, int idx)
    {
        updateUtil(0, 0, n - 1, val, idx);
    }
};

int main()
{
    int n = 5;
    vector<int> arr = {1, 2, 3, 4, 5};

    SegmentTree st(arr);

    cout << "Tree values: " << endl;
    for (int x : st.st)
        cout << x << " ";
    cout << endl;

    cout << st.getSum(2, 4) << endl;
    cout << st.getSum(0, 4) << endl;

    st.update(10, 2);

    cout << "Tree values: " << endl;
    for (int x : st.st)
        cout << x << " ";
    cout << endl;

    cout << st.getSum(2, 2) << endl;
    cout << st.getSum(1, 3) << endl;
    cout << st.getSum(0, 4) << endl;

    return 0;
}