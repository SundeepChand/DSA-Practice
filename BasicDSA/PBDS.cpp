#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

typedef long long ll;

// ll solve(int n, vector<int> tasks)
// {
//     sort(tasks.begin(), tasks.end());

//     ll n1 = 0, n2 = 0;
//     for (int i = 1; i < n; i++)
//         n2 += (tasks[(n - 1) / 2] - tasks[i]);

//     ll ans = n1 + n2;
//     for (int i = 1; i < n; i++)
//     {
//     }
// }

int countOvertake(int n, vector<int> v)
{
    int ans = 0;
    ordered_set s;
    for (int i = 0; i < n; i++)
    {
        s.insert(v[i]);
        ans += (s.size() - s.order_of_key(v[i] + 1));
    }
    return ans;
}

int solve(string a, string b)
{
    map<char, int> m;
    for (int i = 0; i < a.length(); i++)
    {
        m[a[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < b.length(); i++)
    {
        ans += m[b[i]];
    }
    return ans;
}

long long solve(int n, vector<int> c)
{
    set<int> ans;
    int k = 1 << n;
    for (int i = 1; i < k; i++)
    {
        int sum = 0;
        int x = 0;
        for (int j = i; j > 0; j = j >> 1)
        {
            if (j & 1)
            {
                sum += c[x];
            }
            x++;
        }
        if (sum % 2 == 0)
            ans.insert(sum);
    }
    return ans.size();
}

/*
The approach mentioned here has O(n * log n) TC
We sort the intervals based on start/end times and based on that we
find how many elements are greater/less to the given element by storing it
inside an ordered multiset.
*/
int main()
{
    int n = 4;
    vector<int> v = {2, 2, 5, 6};
    cout << solve("abcd", "bd") << endl;
    return 0;
}