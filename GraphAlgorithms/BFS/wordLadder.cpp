#include <bits/stdc++.h>
using namespace std;

class SolutionBF
{
    // TC: O(n * n * m)
public:
    bool dist1(string a, string b)
    {
        int n = a.length(), m = b.length();
        if (n != m)
            return false;

        bool flag = false;
        for (int i = 0, j = 0; i < n; i++, j++)
        {
            if (a[i] != b[j])
            {
                if (flag)
                    return false;
                else
                    flag = true;
            }
        }
        return true;
    }
    int ladderLength(string startWord, string endWord, vector<string> &wordList)
    {
        int n = wordList.size();

        vector<vector<int>> adj(n, vector<int>());
        int endWordIdx = -1;
        for (int i = 0; i < n; i++)
        {
            if (wordList[i] == endWord)
                endWordIdx = i;
            for (int j = 0; j < n; j++)
            {
                if (i != j && dist1(wordList[i], wordList[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // Perform BFS from the endword
        if (endWordIdx == -1)
            return 0;
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);

        queue<int> q;
        q.push(endWordIdx);
        dist[endWordIdx] = 0;
        visited[endWordIdx] = true;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int x : adj[cur])
            {
                if (!visited[x])
                {
                    q.push(x);
                    dist[x] = 1 + dist[cur];
                    visited[x] = true;
                }
            }
        }

        // Find the shortest length by matching the start word
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (dist1(startWord, wordList[i]))
                ans = min(ans, dist[i]);
        }
        if (ans == INT_MAX)
            return 0;
        return ans + 2;
    }
};

class Solution
{
    // TC = O(m * m * n)
public:
    int ladderLength(string startWord, string endWord, vector<string> &wordList)
    {
        wordList.push_back(startWord);
        int n = wordList.size();

        map<string, int> m;
        vector<vector<int>> adj;
        int startWordIdx = -1, endWordIdx = -1;
        for (int i = 0; i < n; i++)
        {
            adj.push_back(vector<int>());
            int u = adj.size() - 1;
            m[wordList[i]] = u;
            if (wordList[i] == endWord)
                endWordIdx = u;
            else if (wordList[i] == startWord)
                startWordIdx = u;

            for (int j = 0; j < wordList[i].length(); j++)
            {
                string key = wordList[i].substr(0, j) + "*" + wordList[i].substr(j + 1);
                if (m.find(key) != m.end())
                {
                    adj[m[key]].push_back(u);
                    adj[u].push_back(m[key]);
                }
                else
                {
                    adj.push_back(vector<int>());
                    m[key] = adj.size() - 1;
                    adj[u].push_back(adj.size() - 1);
                    adj[adj.size() - 1].push_back(u);
                }
            }
        }

        // Perform BFS from the endword
        if (endWordIdx == -1)
            return 0;
        vector<int> dist(adj.size(), INT_MAX);
        vector<bool> visited(adj.size(), false);

        queue<int> q;
        q.push(endWordIdx);
        dist[endWordIdx] = 0;
        visited[endWordIdx] = true;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int x : adj[cur])
            {
                if (!visited[x])
                {
                    q.push(x);
                    dist[x] = 1 + dist[cur];
                    visited[x] = true;
                }
            }
        }

        // Find the shortest path
        int ans = dist[startWordIdx];
        if (ans == INT_MAX)
            return 0;
        return 1 + ans / 2;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    string s, e;
    vector<string> v;
    cin >> s >> e;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        v.push_back(temp);
    }

    Solution sol;
    cout << sol.ladderLength(s, e, v) << endl;
    return 0;
}