#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // Combining all the lists into a single list
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        vector<pair<int, int>> v;
        int k = nums.size();
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < nums[i].size(); j++)
            {
                v.push_back({nums[i][j], i});
            }
        }
        sort(v.begin(), v.end());

        int n = v.size();
        int a = v[0].first, b = v[n - 1].first;
        map<int, int> m;
        for (int i = 0, j = -1; j < n;)
        {
            if (m.size() < k)
            {
                j++;
                if (j < n)
                    m[v[j].second]++;
            }
            if (j < n && m.size() >= k)
            {
                if ((v[j].first - v[i].first) < (b - a))
                    b = v[j].first, a = v[i].first;

                m[v[i].second]--;
                if (m[v[i].second] == 0)
                    m.erase(v[i].second);
                i++;
            }
        }
        return {a, b};
    }
};

class Solution
{
    // Using set data structure.
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {

        int k = nums.size();
        vector<int> next(k, 0);
        set<pair<int, int>> s;
        for (int i = 0; i < k; i++)
        {
            s.insert({nums[i][0], i});
        }

        vector<int> ans = {s.begin()->first, s.rbegin()->first};
        while (!s.empty())
        {
            auto cur = *(s.begin());
            s.erase(s.begin());

            int next_idx = next[cur.second] + 1;
            if (next_idx < nums[cur.second].size())
            {
                next[cur.second]++;
                s.insert({nums[cur.second][next_idx], cur.second});
                int a = s.begin()->first, b = s.rbegin()->first;
                if ((b - a) < (ans[1] - ans[0]))
                {
                    ans[0] = a, ans[1] = b;
                }
            }
            else
                break;
        }
        return ans;
    }
};

int main()
{
    return 0;
}