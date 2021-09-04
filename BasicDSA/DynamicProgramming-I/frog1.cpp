#include <bits/stdc++.h>
using namespace std;

int solveBU(vector<int> &h)
{
    int n = h.size();
    vector<int> dp(n);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        dp[i] = abs(h[i + 1] - h[i]) + dp[i + 1];
        if (i < n - 2)
            dp[i] = min(dp[i], abs(h[i + 2] - h[i]) + dp[i + 2]);
    }
    return dp[0];
}
 
int main()
{
  int n;
  cin>>n;
  vector<int> h(n);
  for (int i = 0; i < n; i++)
  {
    cin>>h[i];
  }
  cout<<solveBU(h)<<endl;
  return 0;
}