#include <bits/stdc++.h>
using namespace std;

/*

01 1 11

*/

int countZeroes(string &s)
{
    int nz = 0;
    for (char c : s)
        c += (c == '0');
    return nz;
}

vector<string> findWinner(vector<string> &specialStrings)
{
    vector<string> ans;
    for (string s : specialStrings)
    {
        int nz = countZeroes(s);
        if (nz % 2 == 1)
            ans.push_back("BERT");
        else if (nz == 2)
            ans.push_back("BERT");
        else
            ans.push_back("TIE");
    }
    return ans;
}

int getMaximizedFunds(int k, int f, vector<int> &price, vector<int> &profit)
{
    int p = price.size();
    vector<pair<int, int>> stocks;
    for (int i = 0; i < p; i++)
    {
        stocks.push_back({price[i], profit[i]});
    }
    sort(stocks.begin(), stocks.end());

    priority_queue<pair<int, int>> pq;
    int i = 0;
    while (k > 0)
    {
        while (i < p and stocks[i].first <= f)
        {
            pq.push({stocks[i].second, -stocks[i].first});
            i++;
        }
        if (pq.size())
        {
            // cout << pq.top().second << " " << pq.top().first << endl;
            f += pq.top().first;
            pq.pop();
            k--;
        }
        else
            break;
    }
    return f;
}

int main()
{
    int k = 2, f = 0;
    vector<int> prices = {0, 1, 1};
    vector<int> profits = {1, 2, 3};
    cout << getMaximizedFunds(k, f, prices, profits);
    return 0;
}