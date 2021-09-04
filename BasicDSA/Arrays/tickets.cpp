#include <bits/stdc++.h>
using namespace std;

int maxTickets(vector<int> tickets)
{
    int n = tickets.size();
    sort(tickets.begin(), tickets.end());

    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        int cur = 1;
        while (i < n && tickets[i] - tickets[i - 1] <= 0)
        {
            cur++;
            i++;
        }
        if (cur > ans)
            ans = cur;
    }
    return ans;
}

int main()
{
    vector<int> t = {8, 5, 4, 8, 4};

    cout<<maxTickets(t)<<endl;
}