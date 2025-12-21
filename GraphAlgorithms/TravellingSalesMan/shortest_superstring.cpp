#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int n;
    vector<vector<int>> cost;
    vector<vector<pair<int, list<int>>>> dp;

public:
    Graph(int n, vector<vector<int>> cost)
    {
        this->n = n;
        this->cost = cost;
        dp = vector<vector<pair<int, list<int>>>>(1 << n, vector<pair<int, list<int>>>(n, make_pair(-1, list<int>())));
    }

    pair<int, list<int>> minCost(int visited, int cur)
    {
        if (visited == (1 << n) - 1)
            return make_pair(0, list<int>());

        if (dp[visited][cur].first != -1)
            return dp[visited][cur];

        int ans = 0;
        list<int> subPath;
        for (int i = 0; i < n; i++)
        {
            if ((visited & (1 << i)) == 0)
            {
                auto tempAns = minCost(visited | (1 << i), i);
                int curCost = cost[cur][i] + tempAns.first;
                if (curCost > ans)
                {
                    ans = curCost;
                    subPath = tempAns.second;
                    subPath.push_front(i);
                }
            }
        }
        return dp[visited][cur] = {ans, subPath};
    }

    vector<int> getHamiltonianPath()
    {
        int ans = 0;
        list<int> path;
        for (int i = 0; i < n; i++)
        {
            auto cur = minCost(1 << i, i);
            if (cur.first > ans)
            {
                ans = cur.first;
                path = cur.second;
                path.push_front(i);
            }
        }
        return vector<int>(path.begin(), path.end());
    }
};

class Solution
{
public:
    int overlap(string a, string b)
    {
        int n = a.length(), m = b.length();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int k = i;
            for (int j = 0; k < n && j < m && a[k] == b[j]; j++, k++)
                ;
            if (k == n)
            {
                ans = max(ans, n - i);
            }
        }
        return ans;
    }
    string shortestSuperstring(vector<string> &words)
    {
        int n = words.size();

        unordered_map<string, int> m;
        for (int i = 0; i < n; i++)
        {
            m[words[i]] = i;
        }

        vector<vector<int>> cost(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    cost[i][j] = 1 + overlap(words[i], words[j]);
                else
                    cost[i][j] = 1;
            }
        }

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //         cout << cost[i][j] << " ";
        //     cout << endl;
        // }

        Graph g(n, cost);
        vector<int> path = g.getHamiltonianPath();
        // cout << "Path: ";
        // for (auto p : path)
        // {
        //     cout << p << " ";
        // }
        // cout << endl;
        string ans;
        if (path.size() > 0)
        {
            int prev = path[0];
            ans = words[path[0]];
            for (int i = 1; i < path.size(); i++)
            {
                string curWord = words[path[i]];
                int charsToRemove = cost[prev][path[i]] - 1;
                ans = ans + curWord.substr(charsToRemove);
                prev = path[i];
            }
        }
        else
        {
            for (int i = 0; i < words.size(); i++)
            {
                ans += words[i];
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    // vector<string> words = {"alex", "loves", "leetcode"};
    vector<string> words = {"catg", "ctaagt", "gcta", "ttca", "atgcatc"};
    // vector<string> words = {"odblnmdfmqormoa", "aaaaaaaaaaaaa", "pcecnhmke", "eqhyocuf", "lntpncu", "chdlwf", "bababaaababbababaaa", "bgcbidecccbagcbdea", "dabecfac", "hgfebjrocqbpkfc", "utlijsrir", "cbdabcbdcc"};
    cout << s.shortestSuperstring(words) << endl;
    return 0;
}