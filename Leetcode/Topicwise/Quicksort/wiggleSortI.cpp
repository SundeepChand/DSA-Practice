#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < (n - 1); i++)
    {
        if (i % 2 == 0)
        {
            if (v[i] > v[i + 1])
                swap(v[i], v[i + 1]);
        }
        else
        {
            if (v[i + 1] > v[i])
                swap(v[i], v[i + 1]);
        }
        cout << v[i] << " ";
    }
    cout << v[n - 1] << endl;
    return 0;
}