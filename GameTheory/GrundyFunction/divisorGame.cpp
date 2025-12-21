/*
Consider the one-pile game with the rule that you may remove c chips from a
pile of n chips if and only if c is a divisor of n, including 1 and n. For example, from a
pile of 12 chips, you may remove 1, 2, 3, 4, 6, or 12 chips. The only terminal position is 0.
Find the Sprague-Grundy function.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> getDivisors(int n)
{
    int rt = sqrt(n);
    vector<int> v;
    for (int i = 1; i <= rt; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            if (i * i != n)
                v.push_back(n / i);
        }
    }
    return v;
}

int mex(unordered_set<int> u)
{
    for (int i = 0; true; i++)
    {
        if (u.find(i) == u.end())
            return i;
    }
    return 0;
}

int main()
{
    int n;
    cin>>n;
    vector<int> grundy(n + 1);

    grundy[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        vector<int> divisors = getDivisors(i);
        unordered_set<int> followers;
        for (int x: divisors)
        {
            int p = i - x;
            followers.insert(grundy[p]);
        }
        grundy[i] = mex(followers);
    }

    cout<<"Grundy values for n = "<<n<<endl;
    for (auto x: grundy)
        cout<<x<<", ";

    // vector<int> div = getDivisors(n);
    // for (auto x: div)
    // {
    //     cout<<x<<", ";
    // }
    return 0;
}