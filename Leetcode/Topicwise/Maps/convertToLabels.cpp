#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

struct Folder
{
    int id, parentId;
    string name;
};

void dfs(
    unordered_map<int, vector<pair<int, string>>> &u,
    int src,
    vector<string> &ans, string cur)
{
    for (auto child : u[src])
    {
        string curStr = cur;
        if (curStr != "")
            curStr += "/";
        curStr += child.second;
        dfs(u, child.first, ans, curStr);
        ans.push_back(curStr);
    }
}

void bfs(unordered_map<int, vector<pair<int, string>>> &u, int src, vector<string> &ans)
{
    queue<pair<int, string>> q;
    q.push({0, ""});

    while (!q.empty())
    {
        pair<int, string> cur = q.front();
        q.pop();
        if (cur.second != "")
            ans.push_back(cur.second);

        for (auto nbr : u[cur.first])
        {
            q.push({nbr.first, cur.second + "/" + nbr.second});
        }
    }
}

vector<string> getLabels(vector<Folder> &v)
{
    unordered_map<int, vector<pair<int, string>>> u;
    for (Folder f : v)
    {
        u[f.parentId].push_back({f.id, f.name});
    }

    vector<string> ans;
    // dfs(u, 0, ans, "");
    bfs(u, 0, ans);
    return ans;
}

int32_t main()
{
    vector<Folder> v = {
        {27, 15, "projects"},
        {81, 27, "novel"},
        {15, 0, "personal"},
        {35, 27, "blog"}};

    vector<string> labels = getLabels(v);
    for (auto x : labels)
        cout << x << endl;

    return 0;
}