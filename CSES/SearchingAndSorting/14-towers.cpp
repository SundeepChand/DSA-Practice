#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    multiset<int> s;
    int tc = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];

        auto it = s.upper_bound(v[i]);
        if (it == s.end())
        {
            tc++;
            s.insert(v[i]);
        }
        else
        {
            s.erase(it);
            s.insert(v[i]);
        }
    }
    cout << tc << endl;
    return 0;
}