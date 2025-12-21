#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool canSolve(vector<int> &A, ll B, ll k)
{
    int n = A.size();
    ll cur = 0, n_sub = 1;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > k)
            return false;
        if (cur + A[i] > k)
        {
            cur = 0;
            n_sub++;
            i--;
        }
        else
        {
            cur += A[i];
        }
    }
    return B >= n_sub;
}

int books(vector<int> &A, int B)
{
    int n = A.size();
    if (B > n)
        return -1;

    ll lb = 0, ub = 1e10, ans = -1;
    while (lb <= ub)
    {
        ll mid = (lb + ub) / 2;
        if (canSolve(A, B, mid))
        {
            ans = mid;
            ub = mid - 1;
        }
        else
            lb = mid + 1;
    }
    return ans;
}

int main()
{
    return 0;
}