#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

void solve(ordered_set &s, int k, int idx)
{
    int kill = (idx + k) % s.size();
    auto it = s.find_by_order(kill);
    cout << *it << " ";
    if (s.size() == 1)
        return;
    s.erase(it);
    solve(s, k, kill);
}

int main()
{
    int n, k;
    cin >> n >> k;

    ordered_set s;
    for (int i = 0; i < n; i++)
        s.insert(i + 1);

    solve(s, k, 0);
    return 0;
}