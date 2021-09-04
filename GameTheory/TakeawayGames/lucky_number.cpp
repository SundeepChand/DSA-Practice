#include<bits/stdc++.h>
using namespace std;

string solve(int n, int a, int b, vector<int> A)
{
    int ctr1 = 0, ctr2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] % a == 0)
            ctr1++;
        else if (A[i] % b == 0)
            ctr2++;
    }
    if (b % a == 0)
        return "Bob";
    if (a % b == 0 && ctr1 != 0 && ctr2 != 0)
        return "Alice";
    if (ctr1 > ctr2)
        return "Bob";
    return "Alice";
}

int main()
{
    vector<int> v {1, 2, 3, 4, 5};
    cout<<solve(5, 3, 2, v)<<endl;
    return 0;
}