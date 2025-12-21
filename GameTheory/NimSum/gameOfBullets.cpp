#include <bits/stdc++.h>
using namespace std;

string solve(int n, vector<int> A)
{
    int temp = 0;
    for (auto x: A)
        temp ^= x;
    if (temp == 0)
        return "Isa";
    return "Gaitonde";
}

int main()
{
    int t;
    cin>>t;

    while (t--)
    {
        int n;
        cin>>n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin>>v[i];

        cout<<solve(n, v)<<endl;
    }
    return 0;
}